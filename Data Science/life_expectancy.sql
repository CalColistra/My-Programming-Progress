use ids6db;
desc Life_Expectancy;
select * from Life_Expectancy;

-- Data Cleansing: --
select count(*) from Life_Expectancy; -- 1108 rows prior to deletion
select count(*) from Life_Expectancy where (Population = 0); -- 252 rows with (population = 0)

-- delete rows where (population = 0):
set SQL_SAFE_UPDATES = 0;
delete from Life_Expectancy where (Population = 0);
-- success: 252 row(s) affected

-- fill in where (total_expenditure = 0) with avg(total_expenditure) where (total_expenditure != 0)
select * from Life_Expectancy where (Total_Expenditure < .5);
select avg(Total_Expenditure) from Life_Expectancy where (Total_Expenditure != 0);
-- avg = 6.2
update Life_Expectancy set Total_Expenditure = 6.2
where (Total_Expenditure = 0);

-- fill in where (Percentage_Expenditure = 0) with avg(Percentage_Expenditure) where(percentage_Expenditure != 0)
select * from Life_Expectancy where (Percentage_Expenditure = 0);
select avg(Percentage_Expenditure) from Life_Expectancy where (Percentage_Expenditure != 0);
-- avg = 1041.79
update Life_Expectancy set Percentage_Expenditure = 1041.79
where (Percentage_Expenditure = 0);


-- delete countries with 0 GDP
delete from Life_Expectancy where (GDP = 0);
-- 7 rows affected

-- delete Palau because Life expectancy, adult mortality & alcohol = 0
delete from Life_Expectancy where (Country = "Palau");

-- delete Tuvalu because  life expectancy & adult mortality = 0
delete from Life_Expectancy where (Country = "Tuvalu");

-- display total count of countries after data cleansing:
select count(Country) from Life_Expectancy;  -- 847

-- List of countries with the highest and lowest average mortality rates (years 2010-2015):
select Country, format(avg(Adult_Mortality), 2) from Life_Expectancy 
group by Country order by avg(Adult_Mortality) asc;
select Country, format(avg(Adult_Mortality), 2) from Life_Expectancy 
group by Country order by avg(Adult_Mortality) desc;
select * from Life_Expectancy where (Country = "Palau");

-- List of countries with the highest and lowest average population (years 2010-2015):
select Country, format(avg(Population), 2) from Life_Expectancy 
group by Country order by avg(Population) asc;
select Country, format(avg(Population), 2) from Life_Expectancy 
group by Country order by avg(Population) desc;


-- List of countries with the highest and lowest average GDP (years 2010-2015):
select Country, format(avg(GDP), 2) from Life_Expectancy 
group by Country order by avg(GDP) asc;
select Country, format(avg(GDP), 2) from Life_Expectancy 
group by Country order by avg(GDP) desc;


-- List of countries with the highest and lowest average Schooling  (years 2010-2015):
select Country, format(avg(Schooling), 2) from Life_Expectancy 
group by Country order by avg(Schooling) asc;
select Country, format(avg(Schooling), 2) from Life_Expectancy 
group by Country order by avg(Schooling) desc;

-- Which countries have the highest and lowest average alcohol consumption (years 2010-2015)?
select Country, format(avg(Alcohol), 2) from Life_Expectancy 
group by Country order by avg(Alcohol) asc;
-- Countries with lowest avg alc consumption:
-- Sudan, Bangladesh, Mauritania, Afghanistan, Pakistan
select Country, format(avg(Alcohol), 2) from Life_Expectancy 
group by Country order by avg(Alcohol) desc;
-- Countries with highest avg alc consumption:
-- Belarus, Lithuania, Austria, Croatia, France, Bulgaria

-- Do densely populated countries tend to have lower life expectancy?
Select Country, Life_Expectancy, Population
from Life_Expectancy order by (Population) desc;
-- countries with highest population: 
-- India, Indonesia, Brazil, Pakistan, Nigeria, Bangladesh, Russia
Select Country, Life_Expectancy, Population
from Life_Expectancy order by Life_Expectancy asc;
-- countries with lowest Life_Expectancy:
-- Haiti, Sierra Leone, Central African Republic, Angola, Lesotho, Chad, Nigeria, Zimbabwe
-- ans: No, except for Nigeria, the densely populated countries don't match the 
-- countries with low life_expectancy
