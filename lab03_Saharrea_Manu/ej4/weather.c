/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"
#include "array_helpers.h"
#include "weather_utils.h"

static const int AMOUNT_OF_WEATHER_VARS = 6 ;

Weather weather_from_file(FILE* file)
{
    Weather weather;
    int weat = fscanf(file, " %d %d %d %u %u %u ",&weather._average_temp, &weather._max_temp,&weather._min_temp,&weather._pressure,&weather._moisture,&weather._rainfall);
    if (weat != AMOUNT_OF_WEATHER_VARS){
      printf("Invalid array.\n");
      exit(EXIT_FAILURE);
    }
    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, EXPECTED_WEATHER_FILE_FORMAT, weather._average_temp, 
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
