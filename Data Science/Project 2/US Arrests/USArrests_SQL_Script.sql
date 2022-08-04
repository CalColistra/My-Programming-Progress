use ids6db;
desc USArrests;
select * from USArrests;
set SQL_SAFE_UPDATES = 0;

-- find missing values:
select * from USArrests where (Assault = 0 OR Murder = 0);

-- find the average of murders excluding the missing value(s):
select AVG(Assault) from USArrests where (Assault != 0);

-- update the missing value with the average:
update USArrests
set Assault = 169.9
where (Assault = 0);

-- find Min, Max, Mean, and Variance of Murder:
select min(Murder), max(Murder), format(avg(Murder),1) as "Mean(Murder)", 
format(variance(Murder),1) as "Variance(Murder)"
from USArrests;

-- find Min, Max, Mean, and Variance of Assualts:
select min(Assault), max(Assault), format(avg(Assault),1) as "Mean(Assault)", 
format(variance(Assault),1) as "Variance(Assault)"
from USArrests;

-- Which state has the maximum murder rate?
select * from USArrests where (Murder = 17.4);

-- List of states in ascending order of urban population percentages:
select State, UrbanPop from USArrests order by (UrbanPop) asc;

-- List states with higher murder rates than Arizona:
select State as "States with Murder Rates greater than Arizona"
from USArrests where (Murder > 8.1);

