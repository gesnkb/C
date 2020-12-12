#include <stdio.h>
#include <math.h>

#define COUNTHOTELS 6
#define COUNTROOMTYPES 5
#define STRINGMAX 64

const char const hotelNames[COUNTHOTELS][STRINGMAX] = {"Marriott", "Hilton", "Best Western", "Holiday Inn", "Motel 6", "Super 8"};

const char const roomNames[COUNTROOMTYPES][STRINGMAX] = {"Standard King", "Standard Two Queens", "Suite Two Queens", "Suite King", "Suite Presidential"};

enum ROOM {StandardKing, Standard2Queen, QueenSuite, KingSuite, PresidentialSuite};

int CostMatrix[COUNTHOTELS][COUNTROOMTYPES] =  
{
    {200, 200, 350, 375, 550},
    {180, 210, 325, 350, 600},
    {125, 125, 240, 250, 400},
    {130, 135, 250, 275, 450},
    {119, 119, 239, 249, 399},
    {118, 118, 240, 247, 389},
};

const char * const GetHotelName(int hotel)
{
    return hotelNames[hotel];
}

const char * const GetRoomName(int room)
{
    return roomNames[room];
}

void PrintHotelRoomsLessThan(int iLimit)
{

    for(int i = 0; i < COUNTHOTELS; i++) {
        for(int j = 0; j < COUNTROOMTYPES; j++){
            if(CostMatrix[i][j] < iLimit){
                printf("%s - %s ($%d)\n", GetHotelName(i), GetRoomName(j), CostMatrix[i][j]);
            }
        }
    }

}

int getMainMenuChoice()
{
    int choice;

    printf("*** Main Menu ***\n 1. Display by hotel\n 2. Display by room type\n 3. Display by price limit\n 4. Exit Program\n");
    scanf("%d", &choice);

    if(choice < 1 || choice > 4){
        printf("*** Error: Please select choice 1 - 4\n");
    }
    return choice;
}

int GetRoomPrice(int hotel, int room)
{
    return CostMatrix[hotel][room];
}

void PrintHotelRoomsByHotel(int hotel)
{

if(hotel < 1 || hotel > 7){
        printf("*** Error: choice out of range\n");
    }

    else
    {

    for(int i = 0; i < COUNTROOMTYPES; i++){
        printf("*** Rooms at %s:\n", GetHotelName(hotel));
        printf("%s - %s ($%d)\n", GetHotelName(hotel), GetRoomName(i), CostMatrix[hotel][i]);
    }
    
    }
}

void PrintHotelOptions()
{
    int hotel; 

    printf("1. Marriott\n 2. Hilton\n 3. Best Western\n 4. Holiday Inn\n 5. Motel 6\n 6. Super 8\n Select a hotel:\n");
    scanf("%d", &hotel);

    PrintHotelRoomsByHotel(hotel - 1);

}


void PrintHotelsByRoom(enum ROOM room)
{
    if(room < 1 || room > 6){
        printf("*** Error: choice out of range\n");
    }

    else
    {
    for(int i = 0; i < COUNTHOTELS; i++){
        printf("*** Hotels with room %s:\n", GetHotelName(room));
        printf("%s - %s ($%d)\n", GetHotelName(i), GetRoomName(room), CostMatrix[i][room]);
    }

    }
}

void PrintRoomOptions()
{
    int room;
    printf("1. Standard King\n 2. Standard Two Queens\n 3. Suite Two Queens\n 4. Suite King\n 5. Suite Presidential\n Select a room:\n");
    scanf("%d", &room);

    PrintHotelsByRoom(room - 1);
    
}


int main(void)
{
    int KeepGoing = 0;
    int choice = 0;
    int price;

    printf("***** Welcome to the Mizzou Accomidations Reservation System (MARS) *****\n");

    do{
        choice = getMainMenuChoice();

        if(choice == 1){
           PrintHotelOptions();
        }

        if(choice == 2){
           PrintRoomOptions();
        }

        if(choice == 3){
            printf("Enter the maximum price in dollars you will pay:\n");
            scanf("%d", &price);
            PrintHotelRoomsLessThan(price);
        }

        if(choice == 4){
            KeepGoing = 4;
        }

    }while(KeepGoing != 4);

    printf("***** Thank you for using MARS! *****\n");

    return 0;

}



