# Digital Dietician

As part of a term project for one of my Spring 2020 classes "Object Oriented Programming", I coded from scratch an application in C++ on Visual Studio that provides recommendations of daily dietary food intake based on the calories required by the user. The program records and stores an already existing users' username, password and in-depth health profile information. This project involved a complex file management system and a non-linear interaction of objects with each other. 

A tour through the program - 

User first Logs in

If the user is a new one 

- He fills a "Health Profile Form" which asks for his name, age, gender, height, weight.
   Based on this information, the program calculates his BMI and BMR
  
- He then fills a "Calories required form" which asks for his activity factor 
   Activity factor is a number representative of whether the user's daily activity level is sedentary (1.53), moderate(1.76) or         active(2.25)
   Based on the above activity factor and the user's BMR, the program calculates the user's total energy expenditure and number of    calories required
      
- Based on the number of calories required by the user, the program implements an algorithm that chooses from a list of food items from a file whose calories when added up fall within a +/- 50 range of the required amount.
   The recommended items are then displayed
   
If the user already exists

- His account is password-protected. Entering the wrong password would ask him to re-enter one. His "Health Profile form" information is already stored in a file and extracted.

- He then fills a "Calories required form" which asks for his activity factor 
   Activity factor is a number representative of whether the user's daily activity level is sedentary (1.53), moderate(1.76) or         active(2.25)
   Based on the above activity factor and the user's BMR, the program calculates the user's total energy expenditure and number of    calories required
      
- Based on the number of calories required by the user, the program implements an algorithm that chooses from a list of food items from a file whose calories when added up fall within a +/- 50 range of the required amount.
   The recommended items are then displayed
   
   
      
 
  
