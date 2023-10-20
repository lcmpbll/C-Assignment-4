#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
const double PI = M_PI;

/******************************************************************************
# Author:           Liam Campbell
# Lab:              Assignment #4
# Date:             October 20th, 2023
# Description:      Estimate the jelly beans in a jelly jar.
# Input:            double jellyLength, jellyHeight
                    int jarSize
# Output:           int estimatedJellies,             
                     numberOfEntries, bestJar
                     double averageNumberOfJellies, 
                      largestJellyBean
# Sources:          None
#******************************************************************************/

int main(void) {
  const double LOAD_FACTOR = 0.698;
  char runAgain[2];
  int jelliesInJar, jarVolume, bestJarJellies = 0, numberOfEntries = 0, bestJar = 0, totalBeans = 0;
  double currentBeanVol, largestJellyBean = 0.0, averageBeansPerJar, jellyLength, jellyHeight;
  
  printf("Welcome to my Jelly Bean Guesser Program!\n\n");
  runAgain[0] = 'y';
  // checks if runAgain still equals yes
  do {
    jelliesInJar = 0;
    // get length and height and jar volume
   printf("Enter the length of a jellybean(cm) \
     and height(cm) of your jelly bean separated by a space: ");
    scanf("%lf %lf", &jellyLength, &jellyHeight);

    printf("Enter the jar size in mL: ");
    scanf("%d", &jarVolume);

    //Calculate bean size
    currentBeanVol = (5 * PI * jellyLength * (pow(jellyHeight, 2)))/24;
    // check to see if this is the largest one
    if(currentBeanVol > largestJellyBean) {
      largestJellyBean = currentBeanVol;
    }

    // estimate jellies in the jar
    jelliesInJar = (jarVolume * LOAD_FACTOR)/currentBeanVol;
    
    // check to see if this jar has the most jellies
    if(jelliesInJar > bestJarJellies){
      bestJar = jarVolume;
      bestJarJellies = jelliesInJar;
    }

    // Keep track of entries
    totalBeans += jelliesInJar;
    numberOfEntries ++;

    // Report out jellies
    printf("Estimate of jelly beans in the jar: %d\n\n", jelliesInJar);
    // check for more entries
    printf("Do you want to enter more (y/n): ");
    scanf(" %c", &runAgain[0]);
    
  } while(runAgain[0] == 'y');

  //check stats 
  averageBeansPerJar = (double)totalBeans / numberOfEntries;

  // print out stats 
  printf("Number of entries: %d\n", numberOfEntries);
  printf("Average number of jelly beans: %0.2lf\n", averageBeansPerJar);
  printf("Largest jelly bean: %0.2lf cm^3\n", largestJellyBean);
  printf("Jar size for largest jelly bean estimate: %d mL\n", bestJar);
  printf("Thank you for using my program!\n");
  return 0;
}