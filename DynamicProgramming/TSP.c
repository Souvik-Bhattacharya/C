#include<stdio.h>
#include<limits.h>

int m[25][25] = {0}, cities, paths, startingCity, optimalOption;

int TSP(int start, int visitedCities[]){
    int min = INT_MAX, flag = 1, visitedCitiesCopy[25];
    visitedCities[start] = 1;
    for(int city = 1; city <= cities; city++){
        if(visitedCities[city] == 0){
            flag = 0;
            for(int city = 1; city <= cities; city++) visitedCitiesCopy[city] = visitedCities[city];
            int cost = m[start][city] + TSP(city, visitedCitiesCopy);
            if(cost < min){
                min = cost;
                optimalOption = city;
            }
        }
    }
    if(flag){
        min = m[start][startingCity];
        optimalOption = startingCity;
    }
    return min;
}

void optimalPath(int start, int visitedCities[]){
    TSP(start, visitedCities);
    printf("%d->", start);
    if(optimalOption != startingCity)  optimalPath(optimalOption,visitedCities);
    else printf("%d", optimalOption);
}

int main()
{
    int s, d, c, visitedCities[25] = {0};
    printf("\nEnter Number of cities:");
    scanf("%d", &cities);
    printf("\nEnter Number of paths:");
    scanf("%d", &paths);
    for(int path = 1; path <= paths; path++){
        printf("\nEnter the source, destination and cost of path %d: ", path);
        scanf("%d %d %d", &s, &d, &c);
        m[s][d] = c;
    }
    printf("\nEnter the starting city:");
    scanf("%d", &startingCity);
    printf("\nThe minimal cost is: %d", TSP(startingCity,visitedCities));
    printf("\nThe optimal path is: %d->", startingCity);
    optimalPath(optimalOption, visitedCities);
    return 0;
}