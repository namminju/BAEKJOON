select id,
case
    when rnk <= (select count(*) from ECOLI_DATA)/4 then 'CRITICAL'
    when rnk <= (select count(*) from ECOLI_DATA)*2/4 then 'HIGH'
    when rnk <= (select count(*) from ECOLI_DATA)*3/4 then 'MEDIUM'
    else 'LOW'
    end as 'COLONY_NAME'
from (
 SELECT 
        id, 
        RANK() OVER (ORDER BY SIZE_OF_COLONY DESC) AS rnk
    FROM ECOLI_DATA
) table1 order by id
; 