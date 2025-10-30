select ss.DEPT_ID, DEPT_NAME_EN, AVG_SAL from (
    select DEPT_ID, round(avg(SAL),0) as AVG_SAL from HR_EMPLOYEES group by DEPT_ID 
order by avg(SAL) desc) ss 
left join HR_DEPARTMENT hd on hd.DEPT_ID = ss.DEPT_ID
;