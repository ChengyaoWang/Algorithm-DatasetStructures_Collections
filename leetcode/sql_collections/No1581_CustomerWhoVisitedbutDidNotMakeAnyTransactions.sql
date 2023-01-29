select      customer_id, count(*) count_no_trans
from        Visits tab0
left join   Transactions tab1
on          tab0.visit_id = tab1.visit_id
where       transaction_id is null
group by    customer_id