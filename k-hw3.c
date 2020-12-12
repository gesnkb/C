#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAXNAME 256

int g_countHotels = 0;
int g_countRooms = 0;

#ifdef BONUS
char ** g_hotelNames;
char ** g_roomNames; 
char ** g_costMatrix;
#else 
#define MAX_HOTEL_NAMES 25
#define MAX_ROOM_TYPES 25
char g_hotelNames[MAX_HOTEL_NAMES][MAXNAME];
char g_roomNames[MAX_ROOM_TYPES][MAXNAME];
int g_costMatrix[MAX_HOTEL_NAMES][MAXNAME];
#endif

const char * const GetHotelName(int hotel);
const char * const GetRoomName(int room);
void PrintHotelOptions();
void PrintRoomOptions();
void PrintHotelRoomsLessThan(int iLimit);
int GetMainMenuChoice();
int GetRoomPrice(int hotel, int room);
void PrintHotelRoomsByHotel(int hotel);
void PrintHotelsByRooms(int room);
int LoadHotelNames(char * sFileName);
int LoadRoomNames(char * sFileName);
int LoadCostMatrix(char * sFileName);
void PrintCostMatrix();
void PrintHotelNames();
void PrintRoomNames();

const char * const GetHotelName(int hotel)
{
    return g_hotelNames[hotel];
}

const char * const GetRoomName(int room)
{
    return g_roomNames[room];
}

void PrintHotelOptions()
{
    int hotel;
    for(int i = 0; i < g_countHotels; i++){
        printf("%d. %s\n", i + 1, g_hotelNames[i]);
    }
    printf("select a hotel\n");
    scanf("%d", &hotel);

    PrintHotelRoomsByHotel(hotel);

}

void PrintRoomOptions()
{
    int room;
    for(int i = 0; i < g_countRooms; i++){
        printf("%d. %s\n", i +1, g_roomNames[i]);
    }

    printf("select a room\n");
    scanf("%d", &room);

    PrintHotelsByRooms(room);
}

void PrintHotelRoomsLessThan(int iLimit)
{
    for(int i = 0; i < g_countHotels; i++){
        for(int j = 0; j < g_countRooms; j++){
            if(g_costMatrix[i][j] < iLimit){
                printf("%s - %s ($%d)\n", GetHotelName(i), GetRoomName(j), g_costMatrix[i][j]);
            }
        }
    }
}

int GetMainMenuChoice()
{ 
 int choice;

    printf("*** Main Menu ***\n 1. Display by hotel\n 2. Display by room type\n 3. Display by price limit\n 4. Exit Program\n");
    printf("Make a selection:");
    scanf("%d", &choice);

    if(choice < 1 || choice > 4){
        printf("*** Error: Please select choice 1 - 4\n");
    }
    return choice;
}

int GetRoomPrice(int hotel, int room)
{
    return g_costMatrix[hotel][room];
}

void PrintHotelRoomsByHotel(int hotel)
{
       for( int i = 0; i < g_countHotels + 1; i++){
            printf("*** Rooms at %s:\n", GetHotelName(hotel - 1));
            printf("%s - %s ($%d)\n", GetHotelName(hotel - 1), GetRoomName(i),g_costMatrix[hotel - 1][i]); 
    }
}

void PrintHotelsByRooms(int room)
{
    for(int i = 0; i < g_countRooms -1; i++){
        printf("*** Hotels with room %s:\n", GetRoomName(room -1));
        printf("%s - %s ($%d)\n", GetHotelName(i), GetRoomName(room -1), g_costMatrix[i][room - 1]);
    }
}

int LoadHotelNames(char * sFileName)
{
    FILE *fPtr = fopen(sFileName, "r");

    if( fPtr == NULL){
        printf("error\n");
        return 0;
    }

        int i = 0;
            fscanf(fPtr, "%d", &g_countHotels);
            for(i = 0; i < g_countHotels; i++){ 
      fscanf(fPtr, "%s", g_hotelNames[i]);
            }
        fclose(fPtr);
        return g_countHotels;
    }

int LoadRoomNames(char * sFileName)
{
    FILE *fPtr = fopen(sFileName, "r");

    if(fPtr == NULL){
        printf("error\n");
            return 0;
        }
        int i = 0;
            fscanf(fPtr, "%d", &g_countRooms);
            for(i = 0; i < g_countRooms; i++){
                fscanf(fPtr, "%s", g_roomNames[i]);
            }
        
        fclose(fPtr);
        return g_countRooms;
}

int LoadCostMatrix(char * sFileName)
{
    FILE *fPtr = fopen(sFileName, "r");

    if(fPtr == NULL){
        printf("error\n");
        return 0;
        }
        int i = 0;
        int j = 0;
            for(i = 0; i < g_countHotels; i++){
                for(j = 0; j < g_countRooms; j++){
            fscanf(fPtr, "%d", &g_costMatrix[i][j]);
            }
        }
            fclose(fPtr);
            return 0;

            
}

void PrintCostMatrix()
{
    for(int i = 0; i < g_countHotels; i++){
        for( int k = 0; k < g_countRooms; k++){
                printf("%s, %s = %d\n", g_hotelNames[i], g_roomNames[k], g_costMatrix[i][k]);
            }
        }
    }

void PrintHotelNames()
{
    for(int i = 0; i <= g_countHotels; i++){
        printf("%s\n", g_hotelNames[i]);
    }

}

void PrintRoomNames()
{
    for(int i = 0; i <= g_countRooms; i++){
        printf("%s\n", g_roomNames[i]);
    }
}

int main(int argc, char * argv[])
{
    if( argc != 4){
        printf("ERROR\n");
    }
    else{
    int KeepGoing = 0;
    int choice = 0;
    int price;
    char *hotelNames = argv[1];
    char *roomTypes = argv[2];
    char *matrix = argv[3];
    
    printf("***** Welcome to the Mizzou Accomidations Reservation System 2.0 (MARS 2.0) *****\n");

    printf("Data Loading....\n");

    printf("Hotel Names\n --------\n");

    LoadHotelNames(hotelNames);
    PrintHotelNames();

    printf("Room Types\n --------\n"); 

    LoadRoomNames(roomTypes); 
    PrintRoomNames();

    printf("Cost Matrix\n --------\n");

    LoadCostMatrix(matrix);
    PrintCostMatrix();

    printf("Data Loaded!\n\n\n");

    do{
        choice = GetMainMenuChoice();

        if(choice == 1){
            PrintHotelOptions();
        }

        if(choice == 2){
            PrintRoomOptions();
        }

        if(choice ==3){
            printf("Enter the maximum price in dollars you will pay:\n");
            scanf("%d", &price);

            printf("*** Rooms less than $%d:\n", price);
            PrintHotelRoomsLessThan(price);
        }

        if(choice == 4){
            KeepGoing = 4;
        }

    }while(KeepGoing != 4);

    printf("***** Thank you for using MARS *****\n");
    }

    return 0;

}
