#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>
#include "AVL.h"
#include "IntAVL.h"
#include "OurBST.h"
#include "IntBST.h"
#include "Animal.h"
#include "City.h"

using namespace std;

void readDataName(OurBST& bst, AVL& AVLtree)
{
	ifstream myfile("Project3Data.csv");
	string line;
	string name;
	string state;
	string strpop;

	auto BST_Start_Time = chrono::high_resolution_clock::now();
	auto AVL_Start_Time = chrono::high_resolution_clock::now();

	while (myfile.is_open())
	{
		//start BST timer
		auto BST_Start = chrono::high_resolution_clock::now();
		BST_Start_Time = BST_Start;
		//insert file in a BST
		int BSTcounter = 0;
		getline(myfile, line);
		while (getline(myfile, name, ','))
		{
			getline(myfile, state, ',');
			getline(myfile, strpop);
			if (strpop != "A")
			{
				int pop = stoi(strpop);
				City* city = new City(name, state, pop);
				bst.insert(city);
			}
			BSTcounter++;
		}
		myfile.close();
		cout << "Data read into BST successfully." << endl;
	}
	//end BST timer
	auto BST_End = chrono::high_resolution_clock::now();
	//calculate BST time elapsed
	auto BST_Time = chrono::duration_cast<chrono::nanoseconds>(BST_End - BST_Start_Time).count();
	cout << "Storing the data in the BST took " << BST_Time << " nanoseconds." << endl;

	//reopen file for AVL tree
	myfile.clear();
	myfile.seekg(0, myfile.beg);
	myfile.open("Project3Data.csv");
	//ifstream myfile ("Project3Data.csv");
	while (myfile.is_open())
	{
		//start AVL timer
		auto AVL_Start = chrono::high_resolution_clock::now();
		AVL_Start_Time = AVL_Start;
		//insert file in a AVL tree
		int AVLcounter = 0;
		getline(myfile, line);
		while (getline(myfile, name, ','))
		{
			getline(myfile, state, ',');
			getline(myfile, strpop);
			if (strpop != "A")
			{
				int pop = stoi(strpop);
				City* city = new City(name, state, pop);
				AVLtree.insert(city);
			}
			AVLcounter++;
		}
		myfile.close();
		cout << "Data read into AVL successfully." << endl;
	}

	//end AVL timer
	auto AVL_End = chrono::high_resolution_clock::now();
	//calculate AVL time elapsed
	auto AVL_Time = chrono::duration_cast<chrono::nanoseconds>(AVL_End - AVL_Start_Time).count();
	cout << "Storing the data in the AVL Tree took " << AVL_Time << " nanoseconds." << endl;
}

void readDataPop(IntBST& bstPop, IntAVL& AVLtreePop)
{
	ifstream myfile("Project3Data.csv");
	string line;
	string name;
	string state;
	string strpop;

	auto BST_Start_Time = chrono::high_resolution_clock::now();
	auto AVL_Start_Time = chrono::high_resolution_clock::now();

	while (myfile.is_open())
	{
		//start BST timer
		auto BST_Start = chrono::high_resolution_clock::now();
		BST_Start_Time = BST_Start;
		//insert file in a BST
		int BSTcounter = 0;
		getline(myfile, line);
		while (getline(myfile, name, ','))
		{
			getline(myfile, state, ',');
			getline(myfile, strpop);
			if (strpop != "A")
			{
				int pop = stoi(strpop);
				City* city = new City(name, state, pop);
				bstPop.insert(city);
			}
			BSTcounter++;
		}
		myfile.close();
		cout << "Data read into BST successfully" << endl;
	}
	//end BST timer
	auto BST_End = chrono::high_resolution_clock::now();
	//calculate BST time elapsed
	auto BST_Time = chrono::duration_cast<chrono::nanoseconds>(BST_End - BST_Start_Time).count();
	cout << "Storing the data in the BST took " << BST_Time << " nanoseconds." << endl;

	//reopen file for AVL tree
	myfile.clear();
	myfile.seekg(0, myfile.beg);
	myfile.open("Project3Data.csv");
	//ifstream myfile ("Project3Data.csv");
	while (myfile.is_open())
	{
		//start AVL timer
		auto AVL_Start = chrono::high_resolution_clock::now();
		AVL_Start_Time = AVL_Start;
		//insert file in a AVL tree
		int AVLcounter = 0;
		getline(myfile, line);
		while (getline(myfile, name, ','))
		{
			getline(myfile, state, ',');
			getline(myfile, strpop);
			if (strpop != "A")
			{
				int pop = stoi(strpop);
				City* city = new City(name, state, pop);
				AVLtreePop.insert(city);
			}
			AVLcounter++;
		}
		myfile.close();
		cout << "Data read into AVL successfully" << endl;
	}

	//end AVL timer
	auto AVL_End = chrono::high_resolution_clock::now();
	//calculate AVL time elapsed
	auto AVL_Time = chrono::duration_cast<chrono::nanoseconds>(AVL_End - AVL_Start_Time).count();
	cout << "Storing the data in the AVL Tree took " << AVL_Time << " nanoseconds." << endl;
}

void printAnimalList()
{
	cout << "\n\tPlease note that these numbers were created with no weapon use by any party.\n" << endl;

	cout << "\tDuck:" << endl;
	cout << "\t\t\t 15 ducks to 1 person" << endl;
	cout << "\t\t\t 0.067 people to 1 duck" << endl;

	cout << "\tLion:" << endl;
	cout << "\t\t\t .08 lions to 1 person" << endl;
	cout << "\t\t\t 12.5 people to 1 lion" << endl;

	cout << "\tT-Rex:" << endl;
	cout << "\t\t\t .0025 T-Rexes to 1 person" << endl;
	cout << "\t\t\t 400 people to 1 T-Rex" << endl;

	cout << "\tFire Ant:" << endl;
	cout << "\t\t\t 750 fire ants to 1 person" << endl;
	cout << "\t\t\t .0013 people to 1 fire ant" << endl;

	cout << "\tGrizzly Bear:" << endl;
	cout << "\t\t\t .0625 grizzly bears to 1 person" << endl;
	cout << "\t\t\t 16 people to 1 grizzly bear" << endl;

	cout << "\tEmu:" << endl;
	cout << "\t\t\t 1 emu to 1 person" << endl;
	cout << "\t\t\t 1 person to 1 emu" << endl;

	cout << "\tSquirrel:" << endl;
	cout << "\t\t\t 22 squirrels to 1 person" << endl;
	cout << "\t\t\t .046 people to 1 squirrel" << endl;

	cout << "\tChimpanzee:" << endl;
	cout << "\t\t\t 2 chimpanzees to 1 person" << endl;
	cout << "\t\t\t .5 people to 1 chimpanzee" << endl;

	cout << "\tGator:" << endl;
	cout << "\t\t\t .1 gators to 1 person" << endl;
	cout << "\t\t\t 10 people to 1 gator" << endl;

	cout << "\tGorilla:" << endl;
	cout << "\t\t\t .05 gorillas to 1 person" << endl;
	cout << "\t\t\t 20 people to 1 gorilla" << endl;
}

void createAnimals(vector<pair<string, float>>& animals)
{
	animals.push_back(make_pair("duck", 15));
	animals.push_back(make_pair("lion", .08));
	animals.push_back(make_pair("t-rex", .0025));
	animals.push_back(make_pair("fire ant", 750));
	animals.push_back(make_pair("grizzly bear", .0625));
	animals.push_back(make_pair("emu", 1));
	animals.push_back(make_pair("squirrel", 22));
	animals.push_back(make_pair("chimpanzee", 2));
	animals.push_back(make_pair("gator", .1));
	animals.push_back(make_pair("gorilla", .05));
}

float getAnimalWeight(string animal, vector<pair<string, float>> animals)
{
	for (auto it = animals.begin(); it != animals.end(); ++it) {
		if (it->first == animal) {
			return it->second;
		}
	}
	return 0.0;
}

void printCityList(vector<City*> cities)
{
	bool firstPrinted = false;
	for (int i = 0; i < cities.size(); i++) {
		if (firstPrinted == false) {
			cout << cities[i]->name;
		}
		else {
			cout << " | " << cities[i]->name;
		}
	}
	cout << endl;
}

int main()
{
	// introduction
	cout << "Hello and welcome to: Lions and Tigers and Bears, Oh My!" << endl;
	cout << "\nThis program will allow you to approxiate the number of a type of animal needed to overthrow any city" << endl;
	cout << "in the United States based off of population data gathered by the US Census Department." << endl;

	// user chooses which option to run
	cout << "\nPlease indicate which process you would like to run:" << endl;
	cout << "\t[1]\tEnter the name of any city in the United States and select an animal from the list that will be provided." << endl;
	cout << "\t\tWe will then tell you the approxiate number of that animal needed to overthrow that city based off population." << endl;
	cout << "\n\t[2]\tSelect one or more animals from the list that will be provided along with the respective quantities and" << endl;
	cout << "\t\twe will then tell you the largest US city that could reasonably be overthrown by your assembled animal army." << endl;

	int userOption = 0;
	cout << "\nPlease make your selection by entering either \"1\" or \"2\": " << endl;
	cin >> userOption;
	cout << "Excellent choice!\n" << endl;

	// create animal weights
	vector<pair<string, float>> animals;
	createAnimals(animals);

	// animal list
	cout << "\nHere is the list of supported animals along with the assocaited data relating to defeating the average human:" << endl;
	printAnimalList();
	cout << "\n" << endl;

	// actually do what user wants
	if (userOption == 1) {

		// read in data - sorted by name
		OurBST bst;
		AVL avl;
		cout << "\nPlease wait while the BST and AVL are read-in..." << endl;
		readDataName(bst, avl);

		string cityChoice, stateChoice;
		cout << "\nPlease enter the city to be overthrown: ";
		cin.ignore();
		getline(cin, cityChoice);
		cout << "In which US state is " << cityChoice << " located: ";
		getline(cin, stateChoice);
		string cityState = cityChoice + ", " + stateChoice;
		string userAnimal;
		cout << "Please select your animal from the above list: ";
		getline(cin, userAnimal);
		transform(userAnimal.begin(), userAnimal.end(), userAnimal.begin(), ::tolower);

		// calculate number of animals needed
		float animalWeight = getAnimalWeight(userAnimal, animals);
		// run search in BST for cityState
		cout << "\nPlease wait while the BST is searched..." << endl;
		auto bstSearchStartTime = chrono::high_resolution_clock::now();
		int popBST = bst.FindCity(cityState)->pop;
		auto bstSearchEndTime = chrono::high_resolution_clock::now();
		float animalsNeededBST = popBST * animalWeight;
		auto bstSearchTime = chrono::duration_cast<chrono::nanoseconds>(bstSearchEndTime - bstSearchStartTime).count();
		cout << "BST has been successfully searched." << endl;
		// run search in AVL for cityState
		cout << "\nPlease wait while the AVL is searched..." << endl;
		auto avlSearchStartTime = chrono::high_resolution_clock::now();
		int popAVL = avl.FindCity(cityState)->pop;
		auto avlSearchEndTime = chrono::high_resolution_clock::now();
		float animalsNeededAVL = popAVL * animalWeight;
		auto avlSearchTime = chrono::duration_cast<chrono::nanoseconds>(avlSearchEndTime - avlSearchStartTime).count();
		cout << "AVL has been successfully searched." << endl;
		// print out results
		cout << "\n[BST] " << cityState << " could be overthrown by " << animalsNeededBST << " " << userAnimal << "s.";
		cout << " Searching through the BST took " << bstSearchTime << " nanoseconds." << endl;
		cout << "\n[AVL] " << cityState << " could be overthrown by " << animalsNeededAVL << " " << userAnimal << "s.";
		cout << " Searching through the AVL Tree took " << avlSearchTime << " nanoseconds." << endl;

	}
	else if (userOption == 2) {

		// read in data - sorted by population
		IntBST bstPop;
		IntAVL avlPop;
		cout << "\nPlease wait while the BST and AVL are read-in...\n" << endl;
		readDataPop(bstPop, avlPop);

		cout << "\nPlease enter the animals you would like to add to your army followed by the number of that animal." << endl;
		cout << "Enter \"-1\" as the animal name when you are done adding." << endl;
		vector<pair<string, int>> userAnimalArmy;
		string userAnimal = "";
		int numOfAnimal;
		while (userAnimal != "-1") {
			cout << "Please enter the animal name: ";
			cin.ignore();
			getline(cin, userAnimal);
			if (userAnimal == "-1") {
				break;
			}
			cout << "Please enter the number of " << userAnimal << "s to add: ";
			cin >> numOfAnimal;
			transform(userAnimal.begin(), userAnimal.end(), userAnimal.begin(), ::tolower);
			userAnimalArmy.push_back(make_pair(userAnimal, numOfAnimal));
		}

		double maxPop = 0;
		for (auto it = userAnimalArmy.begin(); it != userAnimalArmy.end(); ++it) {
			maxPop += (1 / getAnimalWeight(it->first, animals)) * it->second;
		}
		cout << "\nYour animal army could overthrow any city with a population less than " << maxPop << "!" << endl;

		auto bstSearchStartTime = chrono::high_resolution_clock::now();
		City* bstCityOverthrown = bstPop.FindCity(maxPop);
		auto bstSearchEndTime = chrono::high_resolution_clock::now();
		auto bstSearchTime = chrono::duration_cast<chrono::nanoseconds>(bstSearchEndTime - bstSearchStartTime).count();

		auto avlSearchStartTime = chrono::high_resolution_clock::now();
		//search thru AVL and return the city with a pop closest to (without going over) maxPop
		City* avlCityOverthrown = avlPop.FindCity(maxPop);
		auto avlSearchEndTime = chrono::high_resolution_clock::now();
		auto avlSearchTime = chrono::duration_cast<chrono::nanoseconds>(avlSearchEndTime - avlSearchStartTime).count();

		// print results
		cout << "\n[BST] " << bstCityOverthrown->name << " is the largest city that could be overthrown by your animal army" << endl;
		cout << "Population: " << bstCityOverthrown->pop << endl;
		cout << "Searching through the BST took " << bstSearchTime << " nanoseconds." << endl;

		cout << "\n[AVL] " << avlCityOverthrown->name << " is the largest city that could be overthrown by your animal army" << endl;
		cout << "Population: " << avlCityOverthrown->pop << endl;
		cout << "Searching through the AVL Tree took " << avlSearchTime << " nanoseconds." << endl;

	}

	cout << "\nThank you for using Lions and Tigers and Bears, Oh My!" << endl;
	cout << "" << endl;

	return 0;
}
