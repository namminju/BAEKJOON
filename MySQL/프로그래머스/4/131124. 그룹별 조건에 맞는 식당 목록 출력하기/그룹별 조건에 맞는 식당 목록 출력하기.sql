-- 코드를 입력하세요
select MEMBER_NAME, REVIEW_TEXT, date_format(REVIEW_DATE, "%Y-%m-%d") AS REVIEW_DATE  from (select midtable.MEMBER_ID, REVIEW_TEXT, REVIEW_DATE from (select MEMBER_ID from (SELECT MEMBER_ID, count(REVIEW_ID) as cnt from REST_REVIEW group by MEMBER_ID) table2
join
 (select max(cnt) as mcnt from (SELECT MEMBER_ID, count(REVIEW_ID) as cnt from REST_REVIEW group by MEMBER_ID) mc) mtable on table2.cnt = mtable.mcnt) midtable left join REST_REVIEW 
 on REST_REVIEW.MEMBER_ID = midtable.MEMBER_ID) lasttable left join MEMBER_PROFILE 
 on MEMBER_PROFILE.MEMBER_ID = lasttable.MEMBER_ID
 
 order by REVIEW_DATE, REVIEW_TEXT
 ;
 
#  SELECT MEMBER_ID, count(REVIEW_ID) as cnt from REST_REVIEW group by MEMBER_ID) mc