#include <stdio.h>
#include <string.h>

#define MAX_TEAMS 10
#define MAX_PARTICIPANTS 100

// Structure to represent a participant
struct Participant {
    char name[50];
    int age;
    char sport[50];
};

// Structure to represent a team
struct Team {
    char name[50];
    int numParticipants;
    struct Participant participants[MAX_PARTICIPANTS];
};

// Function to add a new participant
void addParticipant(struct Team* team) {
    if (team->numParticipants >= MAX_PARTICIPANTS) {
        printf("Team is full. Cannot add more participants.\n");
        return;
    }

    struct Participant newParticipant;
    printf("Enter participant name: ");
    scanf("%s", newParticipant.name);

    printf("Enter participant age: ");
    scanf("%d", &newParticipant.age);

    printf("Enter participant sport: ");
    scanf("%s", newParticipant.sport);

    team->participants[team->numParticipants] = newParticipant;
    team->numParticipants++;

    printf("Participant added successfully.\n");
}

// Function to display team details
void displayTeam(struct Team team) {
    printf("Team Name: %s\n", team.name);
    printf("Number of Participants: %d\n", team.numParticipants);
    printf("Participants:\n");
    for (int i = 0; i < team.numParticipants; i++) {
        printf("Participant %d:\n", i + 1);
        printf("Name: %s\n", team.participants[i].name);
        printf("Age: %d\n", team.participants[i].age);
        printf("Sport: %s\n", team.participants[i].sport);
        printf("\n");
    }
}

int main() {
    struct Team committee[MAX_TEAMS];
    int numTeams = 0;

    while (1) {
        printf("\nOptions:\n");
        printf("1. Create a new team\n");
        printf("2. Add a participant to a team\n");
        printf("3. Display team details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numTeams >= MAX_TEAMS) {
                    printf("Cannot create more teams. Limit reached.\n");
                    break;
                }

                printf("Enter team name: ");
                scanf("%s", committee[numTeams].name);
                committee[numTeams].numParticipants = 0;
                numTeams++;
                printf("Team created successfully.\n");
                break;

            case 2:
                if (numTeams == 0) {
                    printf("No teams created yet. Please create a team first.\n");
                    break;
                }

                printf("Enter the team name to add participant: ");
                char teamName[50];
                scanf("%s", teamName);

                int teamIndex = -1;
                for (int i = 0; i < numTeams; i++) {
                    if (strcmp(committee[i].name, teamName) == 0) {
                        teamIndex = i;
                        break;
                    }
                }

                if (teamIndex == -1) {
                    printf("Team not found. Please check the team name.\n");
                } else {
                    addParticipant(&committee[teamIndex]);
                }
                break;

            case 3:
                if (numTeams == 0) {
                    printf("No teams created yet.\n");
                    break;
                }

                printf("Enter the team name to display details: ");
                scanf("%s", teamName);

                int teamDisplayIndex = -1;
                for (int i = 0; i < numTeams; i++) {
                    if (strcmp(committee[i].name, teamName) == 0) {
                        teamDisplayIndex = i;
                        break;
                    }
                }

                if (teamDisplayIndex == -1) {
                    printf("Team not found. Please check the team name.\n");
                } else {
                    displayTeam(committee[teamDisplayIndex]);
                }
                break;

            case 4:
                printf("Exiting...");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

