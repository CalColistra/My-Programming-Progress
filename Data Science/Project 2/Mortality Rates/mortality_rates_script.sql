use ids6db;
desc mortality_rates;
set SQL_SAFE_UPDATES = 0;

-- fill in the missing values with medians:
-- give rows without missing values index numbers
SET @row_index := -1;  
  select * from 
  (SELECT @row_index:=@row_index + 1 AS row_index, underFive 
  FROM mortality_rates
  where underFive != 0
  ORDER BY underFive) as subq
  where subq.row_index
  in (FLOOR(@row_index/2) , CEIL(@row_index / 2));
  -- median value for underFive = (69.2+72)/2 = 70.6
  -- now update the missing values for underFive with 70.6
  update mortality_rates
set underFive = 70.6
where (underFive = 0);


-- repeat previous operations bu for the Infant column:
SET @row_index := -1;  
  select * from 
  (SELECT @row_index:=@row_index + 1 AS row_index, Infant 
  FROM mortality_rates
  where Infant != 0
  ORDER BY Infant) as subq
  where subq.row_index
  in (FLOOR(@row_index/2) , CEIL(@row_index / 2));
  -- median value for Infant = (48.6 + 52.1)/2 = 50.35
  -- now update the missing values for Infant with 50.35
  update mortality_rates
set Infant = 50.35
where (Infant = 0);

-- repeat for Neonational column:
SET @row_index := -1;  
  select * from 
  (SELECT @row_index:=@row_index + 1 AS row_index, Neonational 
  FROM mortality_rates
  where Neonational != 0
  ORDER BY Neonational) as subq
  where subq.row_index
  in (FLOOR(@row_index/2) , CEIL(@row_index / 2));
  -- median value for Neonational = 28
  -- now update the missing values for Neonational with 28
  update mortality_rates
set Neonational = 28
where (Neonational = 0);

-- Display the entire table:
select * from mortality_rates;

-- Which years have the lowest and highest infant mortality rates, respectively?
select min(Infant) from mortality_rates;
select * from mortality_rates where Infant = 30.5; 
-- 2016 is the year with lowest Infant mortality rates
select max(Infant) from mortality_rates;
select * from mortality_rates where Infant = 64.8; 
-- 1990 is the year with highest Infant mortality rates

-- In what years the neonatal mortality rates were above average?
select format(avg(Neonational),1) from mortality_rates; 
-- average for Neonational = 27.7
select Year, Neonational from mortality_rates where (Neonational > 27.7);
-- years 1990 to 2004

-- Display the sorted infant mortality rates in descending order.
select year, Infant from mortality_rates order by (Infant) desc;

-- Display min, max, mean, variance, and standard deviation for each mortality rate.
-- for underFive column
select min(underFive), max(underFive), format(avg(underFive),1) as "Mean(underFive)", 
format(variance(underFive),1) as "Variance(underFive)", format(STD(underFive),1)
as "Standard Dev. (underFive)"
from mortality_rates;
-- for Infant column
select min(Infant), max(Infant), format(avg(Infant),1) as "Mean(Infant)", 
format(variance(Infant),1) as "Variance(Infant)", format(STD(Infant),1)
as "Standard Dev. (Infant)"
from mortality_rates;
-- for Neonational column
select min(Neonational), max(Neonational), format(avg(Neonational),1) as "Mean(Neonational)", 
format(variance(Neonational),1) as "Variance(Neonatal)", format(STD(Neonational),1)
as "Standard Dev. (Neonatal)"
from mortality_rates;

-- Add a new column called Above-Five Mortality Rate and populate it with appropriate values. 
-- Hint: Use Alter Table Add Column.
Alter Table mortality_rates 
Add Column AboveFive double;
update mortality_rates
set AboveFive = 68.9;  -- 68.9 is the mean of underFive column

-- Display the entire table again.
select * from mortality_rates;
