/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
private:
    queue<string> waitToCrawl = {};
    vector<thread> workers = {};
    unordered_set<string> seenUrl = {};
    mutex m;
    condition_variable cv;
    bool isDone = false;
    int aliveWorker = 0;
    string rootHostName;
    
    bool isSameHost(const string url){
        int start = url.find("/") + 2;
        int end =  url.find("/", start);
        return rootHostName == url.substr(start, end - start);
    }
    
    void _job(HtmlParser* htmlParser){
        unique_lock<mutex> l(m);
        vector<string> crawlRet;
        string nextUrl;
        
        while(true){
            cv.wait(l, [&](){return !waitToCrawl.empty() || isDone;});
            
            if(isDone)
                return;
            
            ++aliveWorker;
            
            nextUrl = waitToCrawl.front();
            waitToCrawl.pop();
            
            l.unlock();
            crawlRet = htmlParser -> getUrls(nextUrl);
            l.lock();
            
            for(auto& i: crawlRet){
                if(seenUrl.find(i) == seenUrl.end() && isSameHost(i)){
                    waitToCrawl.push(i);
                    seenUrl.insert(i);
                }
                    
            }
            
            --aliveWorker;
            
            if(aliveWorker == 0 && waitToCrawl.size() == 0){
                isDone = true;
                cv.notify_all();
                return;
            }
        }
    }
    
    
    
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        
        // Specify the Domain to Crawl
        int start = startUrl.find("/") + 2;
        int end = startUrl.find("/", start);
        rootHostName = startUrl.substr(start, end - start);
        
        waitToCrawl.push(startUrl);
        seenUrl.insert(startUrl);
        
        int thread_num = thread::hardware_concurrency();
        for(int i = 0; i < thread_num; ++i)
            workers.emplace_back(&Solution::_job, this, &htmlParser);
        
        for(auto &t : workers)
            t.join();

        return vector<string>(seenUrl.begin(), seenUrl.end());

    }
};
