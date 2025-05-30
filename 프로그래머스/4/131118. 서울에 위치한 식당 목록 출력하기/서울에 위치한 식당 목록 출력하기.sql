-- 코드를 입력하세요
# SELECT REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS, ROUND(AVG(REVIIEW_SCORE), 2) AS SCORE FROM REST_INFO, REST_REVIEW GROUP BY REST_ID;

select INFO.REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS, ROUND(AVG(REVIEW_SCORE), 2) AS SCORE
FROM REST_INFO AS INFO, REST_REVIEW AS RE
WHERE INFO.REST_ID = RE.REST_ID AND INFO.ADDRESS like "서울%"
GROUP BY INFO.REST_ID
ORDER BY SCORE DESC, FAVORITES DESC