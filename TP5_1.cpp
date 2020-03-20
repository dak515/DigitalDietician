#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

//// All the operations happen in the last class called "Login"


// Recommendations class has two primary responsibilities
	//// First, it opens and reads from a file which has food items offered by the NYUAD dining hall and
			// the calories associated with each food item
			// The name of the file which stores this data is "Recommendations.txt"
	//// Second, this class has a function that performs an algorithm to pick and choose from the list of 
			// seven food items based on the number of calories required by the user that day
class Recommendations {
private:

	// Vector that'll store names of all food items read from the file
	vector<string> namesOfFood;
	// Vector that'll store the corresponding calories associated with each of the food items
	vector<string> calories;
public:

	// Default-constructor
	// When an object of this class is created, it prints the following
	Recommendations(){
		cout << "			Your recommendations are: " << endl;
		cout << endl;
		cout << endl;
	}

	// This function opens the file of food recommendations and
	// copies the information from the file into the vectors
	void transfer() {

		// Opening the file
		ifstream recsFile("Recommendations.txt", ios::in);
		// If file fails to open, print an error message
		if (recsFile.fail()){
			cerr << "Error opening file" << endl;
			system("pause");
			exit(0);
		}
		
		// Till end of file is not reached
		while (!recsFile.eof()) {
			// Create two temporary strings
			string food;
			string cals;
			// Store food name into string food and calories into string cals
			recsFile >> food >> cals >> ws;
			// Store name of food as an element in the following vector
			namesOfFood.push_back(food);
			// Store number of calories as an element in the following vector
			calories.push_back(cals);
		}
	}

	// This function performs an algorithm to select appropriate food items for the user
		// based on the number of calories the user requires that day
	// The function receives number of calories the user requires that day
	void chooseFood(double c) {
		
		// Initialize a variable that counts number of tries of iterating through the items
			// and finding the appropriate set of food items for the person
		int noOfTries = 0;
		// srand because the random indices generated each time must be different 
		srand((unsigned int)time(0));

		// While number of trials is less than 1000
		while(noOfTries < 1000)  {
			
			// Select 1 random index between 0 and 7 from the list of food items
				// this gives us one stomach-filling main course
			int ind1 = rand() % (7 - 0 + 1) + 0;
			// Select 1 random index between 8 and 12 from the list of food items
				// this gives us one stomach-filling side-dish
			int ind2 = rand() % (12 - 8 + 1) + 8;
			// Select 1 random index between 13 and 17 from the list of food items
				// this gives us one salad
			int ind3 = rand() % (17 - 13 + 1) + 13;
			// Select 1 random index between 18 and 19 from the list of food items
				// this gives us one mediterranean salad
			int ind4 = rand() % (19 - 18 + 1) + 18;
			// Select 1 random index between 20 and 22 from the list of food items
				// this gives us one mediterranean side-dish
			int ind5 = rand() % (22 - 20 + 1) + 20;
			// Select 1 random index between 23 and 25 from the list of food items
				// this gives us one juice
			int ind6 = rand() % (25 - 23 + 1) + 23;
			// Select 1 random index between 26 and 28 from the list of food items
				// this gives us one dessert
			int ind7 = rand() % (28 - 26 + 1) + 26;

			// Since the calories vector stores numerical calorie values as a string,
				// the values are converted to double and stored in each of the following variables
			double x = stod(calories[ind1]);
			double y = stod(calories[ind2]);
			double w = stod(calories[ind3]);
			double z = stod(calories[ind4]);
			double l = stod(calories[ind5]);
			double zz = stod(calories[ind6]);
			double ll = stod(calories[ind7]);

			// The user is presented with 7 food items to each for the day 
				// If the calories for all of them add upto number of calories required by the user
				// (OR) lies within a range of 50 below and 50 above the number of calories required
				// then select that as the list of food items that must be suggested to the user
			if ( x + y + w+z+l+zz+ll == c || ((x+y+w+z+l+zz+ll >= c-50) && (x+y+w+z+l+zz+ll<=c+50))) {
				cout << endl;
				cout << "				You must eat: " << endl;
				cout << endl;
				cout << endl;
				cout << "				" << namesOfFood[ind1] << endl;
				cout << "				 " << "Calories: " << calories[ind1] << endl;
				cout << endl;
				cout << "				" << namesOfFood[ind2] << endl;
				cout << "				 " << "Calories: " << calories[ind2] << endl;
				cout << endl;
				cout << "				" << namesOfFood[ind3] << endl;
				cout << "				 " << "Calories: " << calories[ind3] << endl;
				cout << endl;
				cout << "				" << namesOfFood[ind4] << endl;
				cout << "				 " << "Calories: " << calories[ind4] << endl;
				cout << endl;
				cout << "				" << namesOfFood[ind5] << endl;
				cout << "				 " << "Calories: " << calories[ind5] << endl;
				cout << endl;
				cout << "				" << namesOfFood[ind6] << endl;
				cout << "				 " << "Calories: " << calories[ind6] << endl;
				cout << endl;
				cout << "				" << namesOfFood[ind7] << endl;
				cout << "				 " << "Calories: " << calories[ind7] << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				break;
			}
			// Increment the number of trials
			noOfTries++;
		}
		
	}
};

// This class has the function of receiving health profile data from the user and
	// calculating and displaying their BMI AND BMR (report includes definitions of the aforementioned terms)
	// If the user already exists, he doesn't have to fill the health form again
		// Existing user's health profile has already been stored in the "Directory.txt" file and is 
		// displayed on the screen

class HealthForm {
private:
	// Asks the user to enter the following information
	string name;
	double age;
	string gender;
	double height;
	double weight;
	// Calculates the following based on the above values 
	double BMI;
	double BMR;

public:

	// Default-constructor
		// When an object of this class is created, it asks the username to enter the following information
	HealthForm() {
		std::cout << "		#############################################################################################" << endl;
		std::cout << endl;
		std::cout << endl;
		std::cout << "						     Health Profile" << endl;
		std::cout << endl;
		std::cout << "			Name: ";
		cin >> name;

		std::cout << "			Age: ";
		cin >> age;

		std::cout << "			Gender - " << endl;
		std::cout << "			Type either Male or Female: ";
		cin >> gender;

		// If gender entered is neither, keep asking to re-enter
		while (gender != "Female" && gender != "Male"){
			std::cout << "			Invalid gender: ";
			cin >> gender;
		}

		std::cout << "			Height- " << endl;
		std::cout << "			Enter height in centimeters: ";
		cin >> height;

		std::cout << "			Weight- " << endl;
		std::cout << "			Enter weight in kilograms: ";
		cin >> weight;
	}

	// Function that calculates the Body Mass Index
	void calculateBMI() {
		BMI = (weight)*10000 / (height*height);
	}

	// Function that prints the Body Mass Index
	void printBMI() {
		std::cout << "			Your BMI is: " << BMI << " kg/m^2" << endl;
	}

	// Function that calculates the Basal Metabolic Rate
	void calculateBMR() {
		// Use the following formula if gender is female
		if (gender == "Female") {
			BMR = (10 * weight) + (6.25*height) - (5 * age) - 161;
		}
		// Else use this formula if gender is male
		else if (gender == "Male") {
			BMR = (10 * weight) + (6.25*height) - (5 * age) + 5;
		}
	}

	// Function that prints the Basal Metabolic Rate
	void printBMR() {
		std::cout << "			Your BMR is: " << BMR << " kcal/m^2/h"  << endl;
	}

	// Accessor of name
	string getName() {
		return(name);
	}

	// Accessor of age
	string getAge() {
		return(to_string(age));
	}

	// Accessor of gender
	string getGender() {
		return(gender);
	}

	// Accessor of height
	string getHeight() {
		return(to_string(height));
	}

	// Accessor of weight
	string getWeight(){
		return(to_string(weight));
	}

	// Accessor of BMI
	string getBMI() {
		return(to_string(BMI));
	}

	// Accessor of BMR string
	string getBMR() {
		return(to_string(BMR));
	}

	// Accessor of BMI double
	double getBMRdouble() {
		return(BMR);
	}


};


// An object of this class is created regardless of whether the user is new or not
	// This function's primary role is to get user input on some data and calculate
	// the number of calories required by them on that specific day
class CaloriesRequired {
private:
	// Activity Factor is a factor representative of the amount of activity a person does
	double activityFactor;
	// TEE is the total energy expenditure of the person which is calculated in the functions below
	double TEE;
	// Calories required by the user that day is calculated on the basis of the total energy expenditure that day
	double caloriesNeeded;
public:
	// Default constructor
		// When an object of this class is created, it asks the user to input their activity factor that day
	CaloriesRequired() {
		std::cout << endl;
		std::cout << endl;
		std::cout << "			Activity Factor is a factor representative of the amount of activity a person does" << endl;
		std::cout << endl;
		std::cout << "			Please enter one of the numbers below to represent your activity factor- " << endl;
		std::cout << endl;
		// Instructions for which values one can enter
		std::cout << "			Sedentary active lifestyle:    1.53 " << endl;
		std::cout << "			Moderately active lifestyle:   1.76" << endl;
		std::cout << "			Vigorously active lifestyle:   2.25" << endl;
		std::cout << endl;
		std::cout << endl;
		std::cout << "			Enter your activity factor: ";
		cin >> activityFactor;
		std::cout << endl;
		std::cout << endl;

		// If acitivty factor is invalid then ask the user to re-enter
		while (activityFactor != 1.53 && activityFactor != 1.76 && activityFactor != 2.25) {
			std::cout << "		#############################################################################################" << endl;
			std::cout << endl;
			std::cout << endl;
			std::cout << "					    ****Invalid activity factor****" << endl;
			std::cout << endl;
			std::cout << "			Enter activity factor again: ";
			cin >> activityFactor;
		}
	}

	// This function receives the BMR of the user
	// and multiplies it by the activity factor to calculate the total energy expenditure
	void calculateTEE(double b) {
		TEE = activityFactor * b;
	}

	// Print the total energy expenditure
	void printTEE() {
		std::cout << endl;
		cout << "			Your total energy expenditure is: " << TEE << " kcal/m^2/h" << endl;
	}

	// Calculate the number of calories required by the user
	void calculateCals() {
		caloriesNeeded = TEE + (0.1*TEE);
	}

	// This function prints the number of calories required by the user
	void printCals() {
		std::cout << endl;
		cout << "			Number of calories needed per day is: " << caloriesNeeded << " kcal/m^2/h" << endl;
		std::cout << endl;
		std::cout << endl;
	}

	// Accessor for calories required by the user
	double getCals() {
		return(caloriesNeeded);
	}
};


// This class is where all the operations happen and all objects are made to interact with each other
class Login {
private:
	// Asks user, whether new or existing, to enter a username and a password
	string username;
	string password;

	// Vectors that store each of the corresponding details of existing users from the Directory file into them
	vector<string> dataUsernames;
	vector<string> dataPasswords;
	vector<string> dataName;
	vector<string> dataAge;
	vector<string> dataGender;
	vector<string> dataHeight;
	vector<string> dataWeight;
	vector<string> dataBMI;
	vector<string> dataBMR;

	// This variable temporarily stores words from a file and pushes back into a vector
	string temp1;

	// Index of users data in file
	int index;

public:

	// When object of Login is created, ask user for username and password
	Login() {
		std::cout << endl;
		std::cout << endl;
		std::cout << "		#############################################################################################" << endl;
		std::cout << endl;
		std::cout << endl;
		std::cout << "						    Digital Dietician" << endl;
		std::cout << endl;
		std::cout << endl;
		std::cout << "			Username:	";
		cin >> username;
		std::cout << endl;
		std::cout << "			Password:	";
		cin >> password;
		std::cout << endl;
		std::cout << endl;
	}

	// This function opens the file "Directory" and stores information in vectors
	void openFile(string f) {

		// Opens file
		ifstream infile(f);
		// Print error message if file fails to open
		if (infile.fail()){
			cerr << "Error reading from file" << endl;
			exit(0);
		}

		// Till end of file is reached
		while (!infile.eof()) {

			// Get a line and store it in temp1 variable
			getline(infile, temp1);

			// Initializing two variables start as 0 and end as 1
			int start = 0, end = 1;
			
			// Initializing number of white spaces as 0
			int noOfWhiteSpaces = 0;

			// For as long as the size of the line
			for (int i = 0; i < temp1.size(); i++) {

				// Iterate through every character
					// If a character is a whitespace
				if (temp1[i] == ' '){

					// Store the index of that whitespace into end
					end = i;

					// If it hits the first whitespace then store the previous characters into vector of usernames
					if (noOfWhiteSpaces == 0) {
						dataUsernames.push_back(temp1.substr(start, end - start));
						noOfWhiteSpaces++;
						start = i;
					}

					// If it hits the second whitespace then store the previous characters after the
					// first whitespace into vector of passwords
					else if (noOfWhiteSpaces == 1) {
						dataPasswords.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}
					// If it hits the third whitespace then store the previous characters after the
					// second whitespace into vector of names
					else if (noOfWhiteSpaces == 2) {
						dataName.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}
					// If it hits the fourth whitespace then store the previous characters after the
					// third whitespace into vector of ages
					else if (noOfWhiteSpaces == 3) {
						dataAge.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}
					// If it hits the fifth whitespace then store the previous characters after the
					// fourth whitespace into vector of usernames
					else if (noOfWhiteSpaces == 4) {
						dataGender.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}
					// Similarly for the rest, we do the same
					else if (noOfWhiteSpaces == 5) {
						dataHeight.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}
					else if (noOfWhiteSpaces == 6) {
						dataWeight.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}
					else if (noOfWhiteSpaces == 7) {
						dataBMI.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}
					else if (noOfWhiteSpaces == 8) {
						dataBMR.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}

				}

				// If character hit is end of line, reset number of whitespaces to 0 and get the next line and
				// store it in temporary variable temp
				else if (temp1[i] == '\n'){
					noOfWhiteSpaces = 0;
					start = i;
					getline(infile, temp1);
				}
			}
		}
		// Close file
		infile.close();
	}

	// Function that returns the index of the username that already exists in the file
	// Receives the username
	int getInde(string userName) {
		// Till we reach the end of the vector
		for (int k = 0; k < dataUsernames.size(); k++){
			// Convert username received into a cstring
			const char* w1 = userName.c_str();
			// Convert each of the existing usernames in the vector into a cstring
			const char* w2 = dataUsernames[k].c_str();
			// Compare the above two cstrings
			int c = strcmp(w1, w2);
			// If they are the same
			if (c == 0){
				// Return the index
				return(k);
			}
		}
	}

	// This function performs the most significant operations
	// It checks if the user already exists or not
		//// If the user already exists, it creates an object of CaloriesRequired followed by an object of
			// Recommendations
		//// If the user doesn't already exist, it creates an object of HealthForm, followed by CaloriesRequired
			// followed by Recommendations
	void check(string f) {

		// Initialize variable check to 0
		int check = 0;
		// Till we reach the end of the vector
		for (int i = 0; i < dataUsernames.size(); i++) {
			// Convert each of the existing usernames in the vector into a cstring
			const char* c1 = dataUsernames[i].c_str();
			// Convert username entered by the user into a cstring
			const char* c2 = username.c_str();
			// Check is set to 0 if both the cstrings being compared are the same
			check = strcmp(c1, c2);
			// If they are the same
			if (check == 0){
				// Store the index of that existing username into variable index
				index = i;
				// Break from the loop
				break;
			}
		}

		// If the two cstrings are the same
		if (check == 0) {
			// While corresponding password in the vector of passwords is not the same as the password entered by the user
			while (dataPasswords[index] != password) {
				// Display incorrect password and enter again
				std::cout << "					   **** Incorrect Password ****" << endl;
				std::cout << endl;
				std::cout << endl;
				std::cout << "			Username:               " << username;
				cout << endl;
				std::cout << endl;
				std::cout << "			Enter password again:	";
				cin >> password;
			}


			// When the password entered is correct, display the already existing health profile
			std::cout << "		#############################################################################################" << endl;
			std::cout << endl;
			std::cout << endl;
			cout << "					    Your health profile already exists" << endl;
			std::cout << endl;
			std::cout << endl;
			// The following information already exists
			cout << "			Name:		" << dataName[index] << endl;
			cout << "			Age:		" << dataAge[index] << " years" << endl;
			cout << "			Gender:		" << dataGender[index] << endl;
			cout << "			Height:		" << dataHeight[index] << " cms" << endl;
			cout << "			Weight:		" << dataWeight[index] << " kgs" << endl;
			cout << "			BMI:		" << dataBMI[index] << " kgs/m^2" << endl;
			cout << "			BMR:		" << dataBMR[index] << " kcal/m^2/h" << endl;
			std::cout << endl;
			std::cout << endl;
			

			// The following algorithm asks the user to hit N to move to the
				// next section of the program
				// If the user hits any other key instead of N, it identifies it as incorrect and
				// keeps asking to hit N until the user does
			char nextOne;
			cout << "			Hit 'N' for NEXT: ";
			cin >> nextOne;
			cout << endl;
			if (nextOne != 'N') {
				while (nextOne != 'N') {
					cout << "			Hit 'N' for NEXT: ";
					cin >> nextOne;
					cout << endl;
					if (nextOne == 'N'){
						break;
					}
				}
			}

			cout << endl;
			cout << endl;
			std::cout << "		#############################################################################################" << endl;
			cout << endl;
			cout << endl;

			// An object of this class is now created
			CaloriesRequired cExisting;
			// Calculates the total energy expenditure of the person on receiving the BMR
			cExisting.calculateTEE(stod(dataBMR[index]));
			// Prints the total energy expenditure
			cExisting.printTEE();
			// Calculates the calories required by the person on that day
			cExisting.calculateCals();
			// Prints the calories required by the person on that day
			cExisting.printCals();

			// Following is the second time we ask the user to hit N to continue
			char nextTwo;
			cout << "			Hit 'N' for NEXT: ";
			cin >> nextTwo;
			cout << endl;
			if (nextTwo != 'N') {
				while (nextTwo != 'N') {
					cout << "			Hit 'N' for NEXT: ";
					cin >> nextTwo;
					cout << endl;
					if (nextTwo == 'N'){
						break;
					}
				}
			}

			cout << endl;
			cout << endl;
			std::cout << "		#############################################################################################" << endl;
			cout << endl;
			cout << endl;

			// An object of the following class is created now
			Recommendations rExisting;
			// Opens file and copies all information into vectors
			rExisting.transfer();	

			cout << endl;
			

			// This is the third time in the program where we pause and ask the user to
				// hit N before moving on
			char nextThree;
			cout << "			Hit 'N' for NEXT: ";
			cin >> nextThree;
			cout << endl;
			if (nextThree != 'N') {
				while (nextThree != 'N') {
					cout << "			Hit 'N' for NEXT: ";
					cin >> nextThree;
					cout << endl;
					if (nextThree == 'N'){
						break;
					}
				}
			}

			// Choose food for the user based on number of calories required
			rExisting.chooseFood(cExisting.getCals());

		}

		// If the user is new and not already existing
		else if (check != 0) {
			ofstream outfile;
			// Open the file and add information only at the end, don't erase and rewrite the file
			outfile.open(f, ios::app);
			
			// If the file fails to open, print an error message
			if (outfile.fail()){
				cerr << "Error reading into file" << endl;
				exit(0);
			}
			
			// An object of this class is created to get all of the users data
			HealthForm hNew;
			// Calculates the BMI of the new user
			hNew.calculateBMI();
			// Prints the BMI of the new user
			hNew.printBMI();
			// Calculate the BMR of the new user
			hNew.calculateBMR();
			// Print the BMR of the new user
			hNew.printBMR();

			std::cout << endl;
			std::cout << endl;

			// This is the fourth time we ask the user to hit N to move on
			char nextFour;
			cout << "			Hit 'N' for NEXT: ";
			cin >> nextFour;
			cout << endl;
			if (nextFour != 'N') {
				while (nextFour != 'N') {
					cout << "			Hit 'N' for NEXT: ";
					cin >> nextFour;
					cout << endl;
					if (nextFour == 'N'){
						break;
					}
				}
			}

			std::cout << endl;
			std::cout << endl;
			std::cout << "		#############################################################################################" << endl;
			std::cout << endl;
			std::cout << endl;

			// Store the new username into the vector of usernames
			dataUsernames.push_back(username);
			// Return the index of the username we just stored in the vector
			index = getInde(username);

			// Store all the corresponding information into the vectors
			dataPasswords.push_back(password);
			dataName.push_back(hNew.getName());
			dataAge.push_back(hNew.getAge());
			dataGender.push_back(hNew.getGender());
			dataHeight.push_back(hNew.getHeight());
			dataWeight.push_back(hNew.getWeight());
			dataBMI.push_back(hNew.getBMI());
			dataBMR.push_back(hNew.getBMR());

			cout << endl;

			// Store all the information at the end of the file in one single row seperated by a whitespace
			outfile << "\n" << dataUsernames[index] << ' ' << dataPasswords[index] << ' ' << hNew.getName() << ' ' << hNew.getAge() << ' ' << hNew.getGender() << ' ' << hNew.getHeight() << ' ' << hNew.getWeight() << ' ' << hNew.getBMI() << ' ' << hNew.getBMR() << ' ';
			// Close the file
			outfile.close();

			// Create an object of calories required
			CaloriesRequired cNew;
			// Calculate the total energy expenditure based on the BMR of the user
			cNew.calculateTEE(stod(hNew.getBMR()));
			// Print the total energy expenditure of the user
			cNew.printTEE();
			// Calculate the calories required by the user 
			cNew.calculateCals();
			// Print the calories required by the user
			cNew.printCals();
			
			std::cout << endl;
			std::cout << endl;

			// This is the fifth time we ask the user to hit N to move on
			char nextFive;
			cout << "			Hit 'N' for NEXT: ";
			cin >> nextFive;
			cout << endl;
			if (nextFive != 'N') {
				while (nextFive != 'N') {
					cout << "			Hit 'N' for NEXT: ";
					cin >> nextFive;
					cout << endl;
					if (nextFive == 'N'){
						break;
					}
				}
			}


			std::cout << endl;
			std::cout << endl;
			std::cout << "		#############################################################################################" << endl;
			std::cout << endl;
			std::cout << endl;

			// Crreate an object of recommendations class
			Recommendations rNew;
			// Open file and copy information into vectors
			rNew.transfer();

			std::cout << endl;
			std::cout << endl;

			// This is the sixth time we ask the user to hit N to move on
			char nextSix;
			cout << "			Hit 'N' for NEXT: ";
			cin >> nextSix;
			cout << endl;
			if (nextSix != 'N') {
				while (nextSix != 'N') {
					cout << "			Hit 'N' for NEXT: ";
					cin >> nextSix;
					cout << endl;
					if (nextSix == 'N'){
						break;
					}
				}
			}

			std::cout << endl;
			std::cout << endl;
			
			// Based on the number of calories required by the user, choose food
			rNew.chooseFood(cNew.getCals());
		}

	}
};

int main()
{	// The file where all existing users data is stored
	string file = "Directory.txt";
	// Create an object of Login where all the main operations take place
	Login L;
	// This function opens the file Directory
	L.openFile(file);
	// This function checks if the user already exists in the file
	L.check(file);
	system("pause");
	return(0);

}