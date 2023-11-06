#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#pragma warning(disable:4996)
// I use this warning because of the scanf function


/*******
Amit Chemerinsky
322211590
83120-02
Ex4
********/

const int MAXSIZE = 80;

struct Player {
	char* name;
	int jerseyNumbers;
	int points[5];
	float average;
};

struct Team {
	char* captainName;
	Player players[MAXSIZE];
	int numPlayers;
};

// functions prototypes
void setPlayer(Team* ptrTeam);
void calculateAverage(Player* ptrPlayer);
void bestPlayer(Team* ptrTeam);
void setTeam(Team* ptrTeam);
void worstPlayer(Team* ptrTeam);
void printTeamInfo(Team* ptrTeam);
void printTeamAverage(Team* ptrTeam);

int main()
{
	Team team;
	Team* ptrTeam = &team;
	Player player;
	Player* ptrPlayer = &player;
	ptrTeam->numPlayers = 0;

	setTeam(ptrTeam);
	int choice;
	do
	{
		printf("Would you like to buy a player (1) yes (else) no? \n");
		scanf("%d", &choice);
		if (choice == 1) // yes
		{
			setPlayer(ptrTeam);
		}

	} while (choice == 1);

	printf("There are %d players on the team. \n", ptrTeam->numPlayers);
	if (ptrTeam->numPlayers == 0) {
		printf("There are no players.");
		return 1;
	}

	calculateAverage(ptrPlayer);
	bestPlayer(ptrTeam);
	worstPlayer(ptrTeam);
	printTeamAverage(ptrTeam);
	printTeamInfo(ptrTeam);

	// free the allocated memory
	free(ptrTeam->captainName);
	for (int i = 0; i < ptrTeam->numPlayers; i++) {
		free(ptrTeam->players[i].name);
		}

	return 0;
}

/*************************************************************************
Function name: setTeam
Input: pointer to a Team struct
Output: None
The function operation: It prompts the user to enter the manager's name, allocates memory for the
captainName field of the team, copies the manager's name to the captainName field, and frees the memory
allocated for the captainName field.
************************************************************************/

void setTeam(Team* ptrTeam) {
	char tempManagerName[MAXSIZE];
	printf("Hello, please enter manager's name: \n");
	scanf("%s", tempManagerName);

	// Allocate memory for the captainName field of the team
	int len = strlen(tempManagerName);
	ptrTeam->captainName = (char*)malloc((len + 1) * sizeof(char));

	// Check if memory allocation was successful
	if (ptrTeam->captainName == NULL) {
		return;
	}

	// Copy the manager's name to the captainName field
	strcpy(ptrTeam->captainName, tempManagerName);
	ptrTeam->captainName[len] = '\0';

	return;
}

/*************************************************************************
Function name: setPlayer
Input: pointer to a Team struct
Output: None
The function operation: It prompts the user to enter the player's name, allocates memory for the player's name,
copies the player's name, frees the memory allocated for the player's name, prompts the user to enter the player's
jersey number and point history, increments the number of players in the team, and calls the calculateAverage
function to calculate the player's average.
************************************************************************/

void setPlayer(Team* ptrTeam) {
	char tempName[MAXSIZE];
	printf("Player name? \n");
	scanf("%s", tempName);

	// Allocate memory for the player's name
	int len = strlen(tempName);
	ptrTeam->players[ptrTeam->numPlayers].name = (char*)malloc((len + 1) * sizeof(char));

	// Copy the player's name
	strcpy(ptrTeam->players[ptrTeam->numPlayers].name, tempName);
	ptrTeam->players[ptrTeam->numPlayers].name[len] = '\0';

	// Get player's jersey number
	printf("Jersey number? \n");
	scanf(" %d", &ptrTeam->players->jerseyNumbers);

	// Get player's point history
	printf("Player point history? \n");
	int i;
	for (i = 0; i < 5; i++) {
		scanf("%d", &ptrTeam->players[ptrTeam->numPlayers].points[i]);
		while (ptrTeam->players[ptrTeam->numPlayers].points[i] < 0 || ptrTeam->players[ptrTeam->numPlayers].points[i] > 1000) {
			scanf("%d", &ptrTeam->players[ptrTeam->numPlayers].points[i]);
		}
	}
	ptrTeam->numPlayers++;
	calculateAverage(&ptrTeam->players[ptrTeam->numPlayers - 1]);
}

/*************************************************************************
Function name: calculateAverage
Input: pointer to a Player struct
Output: None
The function operation: It takes a pointer to a Player struct as an argument and calculates the average
of the player's points by summing up the values in the points array and dividing by 5. The result is stored
in the average field of the Player struct.
************************************************************************/

void calculateAverage(Player* ptrPlayer) {
	// Initialize sum to 0
	int sum = 0;
	int i;
	// Iterate through the player's points
	for (i = 0; i < 5; i++) {
		sum += ptrPlayer->points[i];
	}
	// Calculate the average
	ptrPlayer->average = float(sum) / 5;
}

/*************************************************************************
Function name: bestPlayer
Input: pointer to a Team struct
Output: None
The function operation: It takes a pointer to a Team struct as an argument, iterates through the team's
players, compares the current player's average with the current highest average, updates the best player 
index accordingly. Finally, it prints the name, jersey number, and average of the best player.
************************************************************************/

void bestPlayer(Team* ptrTeam) {
	int temp = 0;
	int bestPlayerIndex = 0;
	// Iterate through the team's players
	for (int i = 0; i < ptrTeam->numPlayers; i++) {
		// Compare the current player's average with the current highest average
		if (ptrTeam->players[i].average > temp) {
			temp = ptrTeam->players[i].average;
			bestPlayerIndex = i;
		}
	}
	printf("Best player is %s, ", ptrTeam->players[bestPlayerIndex].name);
	printf("with jersey number of %d. ", ptrTeam->players[bestPlayerIndex].jerseyNumbers);
	printf("Average is %f. \n", ptrTeam->players[bestPlayerIndex].average);
}

/*************************************************************************
Function name: worstPlayer
Input: pointer to a Team struct
Output: None
The function operation: It takes a pointer to a Team struct as an argument, iterates through the team's
players, compares the current player's average with the current lowest average, updates the worst player
index accordingly. Finally, it prints the name, jersey number, and average of the worst player.
************************************************************************/

void worstPlayer(Team* ptrTeam) {
	int temp = 1000000;
	int worstPlayerIndex = 0;
	// Iterate through the team's players
	for (int i = 0; i < ptrTeam->numPlayers; i++) {
		// Compare the current player's average with the current lowest average
		if (ptrTeam->players[i].average < temp) {
			temp = ptrTeam->players[i].average;
			worstPlayerIndex = i;
		}
	}
	printf("Worst player is %s, ", ptrTeam->players[worstPlayerIndex].name);
	printf("with jersey number of %d. ", ptrTeam->players[worstPlayerIndex].jerseyNumbers);
	printf("Average is %f. \n", ptrTeam->players[worstPlayerIndex].average);

}

/*************************************************************************
Function name: printTeamInfo
Input: pointer to a Team struct
Output: None
The function operation: It takes a pointer to a Team struct as an argument, prints the manager's name,
and iterates through the team's players, printing their names.
************************************************************************/

void printTeamInfo(Team* ptrTeam) {
	printf("Manager is %s\n", ptrTeam->captainName);
	printf("Players are: \n");
	// // Iterate through the team's players
	for (int i = 0; i < ptrTeam->numPlayers; i++) {
		printf("%s\n", ptrTeam->players->name);
	}
}

/*************************************************************************
Function name: printTeamAverage
Input: pointer to a Team struct
Output: None
The function operation: It takes a pointer to a Team struct as an argument, iterates through the team's 
players and their points, calculates the total points, calculates the team's average and prints the team's
average.
************************************************************************/

void printTeamAverage(Team* ptrTeam) {
	// Initialize totalPoints to 0
	float totalPoints = 0;
	// Iterate through the team's players
	for (int i = 0; i < ptrTeam->numPlayers; i++) {
		// Iterate through the player's points
		for (int j = 0; j < 5; j++) {
			totalPoints += ptrTeam->players[i].points[j];
		}
	}
	// Calculate the team's average
	float teamAverage = totalPoints / (5 * ptrTeam->numPlayers);
	printf("Team average is %f.\n", teamAverage);
}

