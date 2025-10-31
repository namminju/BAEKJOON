-- 코드를 입력하세요
select tb3.* from (
    select * from (
        SELECT HOST_ID, count(*) as cnt
        from PLACES 
        group by HOST_ID
        )tb1
        where tb1.cnt>=2
    ) tb2
left join PLACES tb3 on tb2.HOST_ID = tb3.HOST_ID
order by id
;