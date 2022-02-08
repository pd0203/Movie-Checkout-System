#include "MediaFactory.h" 

// ---------------------------createMedia-------------------------------
// createMedia: outputs created media object based on the description of 
//              single media item in text file
// preconditions:  file is properly formatted and movieGenre is one of 
//                 'C' or 'F' or 'D'
// postconditions: Media object fulfilling the requirements is created
//                 and returned 
// -------------------------------------------------------------------
Media* MediaFactory::createMedia(istream& file, char& movieGenre) {
	Media* movieNode;
	int stock = -1;
	switch (movieGenre) {
	case 'F':
		createComedy(file, movieNode);
		break;

	case 'C':
		createClassic(file, movieNode);
		break;
	case 'D':
		createDrama(file, movieNode);
		break;
	default:
		return NULL;
	}
	return movieNode;
}


// ---------------------------createComedy-------------------------------
// createComedy: outputs Media pointer, which points to created new 
//               comedy object as a parameter
// preconditions:  file is properly formatted 
// postconditions: comedy object fulfilling the requirements is created
//                 and returned
// -------------------------------------------------------------------
void MediaFactory::createComedy(istream & file, Media*& movieNode) {
	string sentence, token;

	getline(file, sentence);
	stringstream ss(sentence);
	vector<string> comedyData;
	int commaCount = 0;
	while (getline(ss, token, ',') && commaCount != 4) {
		if (token != "") {
			if (token.at(0) == ' ') {
				token.erase(0, 1);
			}
			comedyData.push_back(token);
			commaCount++;
		}
	}

	int  movieStock = stoi(comedyData[0]);
	string directorName = comedyData[1];
	string movieName = comedyData[2];
	int year = stoi(comedyData[3]);

	movieNode = new Comedy();
	movieNode->setBaseCount(movieStock);
	movieNode->setDirector(directorName);
	movieNode->setTitle(movieName);
	movieNode->setYear(year);
}


// ---------------------------createClassic-------------------------------
// createClassic: outputs Media pointer, which points to created new 
//                classic object as a parameter
// preconditions:  file is properly formatted
// postconditions: classic object fulfilling the requirements is created
//                 and returned
// -------------------------------------------------------------------
void MediaFactory::createClassic(istream & file, Media*& movieNode) {
	string line, token1, token2;
	getline(file, line);
	stringstream ss(line);
	vector<string> classicData, tempData;
	int commaCount = 0, blankCount = 0;
	while (getline(ss, token1, ',') && commaCount != 4) {
		if (token1 != "") {
			if (token1.at(0) == ' ') {
				token1.erase(0, 1);
			}
			classicData.push_back(token1);
			commaCount++;
		}
	}

	int movieStock = stoi(classicData[0]);
	string directorName = classicData[1];
	string movieName = classicData[2];
	string actorMonthYear = classicData[3];

	stringstream actMonYear(actorMonthYear);
	while (getline(actMonYear, token2, ' ') && blankCount != 4) {
		if (token2 != "") {
			if (token2.at(0) == ' ') {
				token2.erase(0, 1);
			}
			tempData.push_back(token2);
			blankCount++;
		}
	}
	string actorFName = tempData[0];
	string actorLName = tempData[1];
	int month = stoi(tempData[2]);
	int year = stoi(tempData[3]);
	string actorName = actorFName + " " + actorLName;

	movieNode = new Classic(actorName, month);
	movieNode->setBaseCount(movieStock);
	movieNode->setDirector(directorName);
	movieNode->setTitle(movieName);
	movieNode->setYear(year);
}


// ---------------------------createDrama-------------------------------
// createDrama: outputs Media pointer, which points to created new 
//              drama object as a parameter
// preconditions:  file is properly formatted
// postconditions: drama object fulfilling the requirements is created
//                 and returned
// -------------------------------------------------------------------
void MediaFactory::createDrama(istream & file, Media*& movieNode) {
	string sentence, token;
	getline(file, sentence);
	stringstream ss(sentence);
	vector<string> dramaData;
	int commaCount = 0;
	while (getline(ss, token, ',') && commaCount != 4) {
		if (token != "") {
			dramaData.push_back(token);
			commaCount++;
		}
	}
	int movieStock = stoi(dramaData[0]);
	string directorName = dramaData[1];
	string movieName = dramaData[2];
	int year = stoi(dramaData[3]);

	directorName.erase(0, 1);
	movieName.erase(0, 1);

	movieNode = new Drama();
	movieNode->setBaseCount(movieStock);
	movieNode->setDirector(directorName);
	movieNode->setTitle(movieName);
	movieNode->setYear(year);
}