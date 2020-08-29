from datetime import datetime



def timer(func):
    def wrapper(*args, **kw):
        start = datetime.now()
        value = func(*args, **kw)
        print(f'Time Elapsed for {func.__name__}: {datetime.now() - start}')
        return value
    return wrapper