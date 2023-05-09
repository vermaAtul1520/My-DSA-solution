# Write your MySQL query statement below

# UPDATE SALARY SET SEX=IF(SEX='m','f','m');

UPDATE Salary
SET sex = CASE sex
        WHEN 'm' THEN 'f'
        WHEN 'f' THEN 'm'
        END;