#include <iostream>

// For User to interact with to input data
void InteractionforUser(int& milesnow, int& milesbefore, int& Googlehours, int& Googleminutes, int& CurrenttimeHour, int& CurrenttimeMinute, int& PastTimeHour, int& PastTimeMinute) {
    std::cout << "Enter the Miles remaining for trip" << std::endl;
    std::cin >> milesnow;
    std::cout <<  "Enter the Miles you travelled in the previous estimate" << std::endl;
    std::cin >> milesbefore;

    std::cout << "Put in the Hours from google in 24 hour EST it says for arrival time" << std::endl;
    std::cin >> Googlehours;
    std::cout << "Put in the Minutes" << std::endl;
    std::cin >> Googleminutes;

    std::cout << "Put in the current time in 24 hours EST for hours" << std::endl;
    std::cin >> CurrenttimeHour;
    std::cout << "Put in the current time in minutes" << std::endl;
    std::cin >> CurrenttimeMinute;

    std::cout << "Put in the time before from last calculation in hours" << std::endl;
    std::cin >> PastTimeHour;
    std::cout << "Put in the time before from last calcuation in minutes" << std::endl;
    std::cin >> PastTimeMinute;

}

void AverageSpeed(int milesfrombefore, int milesleft, int CurrenttimeinHour, int CurrenttimeinMinutes, int PastTimeinHours, int PastTimeinMinutes, int& AverageSpeed) { // Averaging out speed from Time and miles driven
    int internaltimehour,
    internaltimeminute,
    internalmiles;

    internaltimehour = CurrenttimeinHour - PastTimeinHours;
    internaltimeminute = CurrenttimeinMinutes - PastTimeinMinutes;
    internalmiles = milesfrombefore - milesleft;

    internaltimeminute = internaltimeminute + internaltimehour * 60;
    AverageSpeed = internaltimeminute/internalmiles; 


}

void TimeEstimatefromhere(int CurrenttimeHour, int CurrenttimeMinute, int Milesleft, int& Timestimatehours, int& TimestimateMinutes, int averagespeed) {
    averagespeed = averagespeed/60; //Divide to convert MPH to Miles per minute
    TimestimateMinutes = Milesleft/averagespeed;
    while (TimestimateMinutes > 60) { // Subtracting and adding to get time estimate from minutes to hours and minutes
        TimestimateMinutes = TimestimateMinutes - 60;
        Timestimatehours = Timestimatehours + 1;
    }
}

void ETA (int timestimatedhour, int timestimatedminute, int timecurrenthour, int timecurrentminute, int& ETAHour, int& ETAMinute) { // Adding Current time and estimated time for ETA
    ETAHour = timestimatedhour + timecurrenthour;
    ETAMinute = timestimatedminute + timecurrentminute;
}

void Showingoffdata(int CurrenttimeinHour, int CurrenttimeinMinutes, int averagespeed, int googlehours, int googleminutes, int timestimatedhours, int timestimatedminutes, int ETAHour, int ETAMinute) {
    std::cout << "Average Speed " << averagespeed << " MPH" << std::endl;
    std::cout << "ETA " << ETAHour << ":" << ETAMinute << std::endl;
    std::cout << "Google maps ETA " << googlehours << ":" << googleminutes << std::endl;
    std::cout << "time remaining " << timestimatedhours << ":" << timestimatedminutes << std::endl;
}

int main() { // Main loop
    while (true) {
        int milesleft,
        milesfrombefore,
        googlehours,
        googleminutes,
        CurrenttimeinHour,
        CurrenttimeinMinutes,
        TimestimatecalculatedHours,
        TimestimatecalculatedMinutes,
        PastTimeinMinutes,
        PastTimeinHours,
        averagespeed,
        TimeETAHour,
        TimeETAMinute;
        InteractionforUser (milesleft, milesfrombefore, googlehours, googleminutes, CurrenttimeinHour, CurrenttimeinMinutes, PastTimeinHours, PastTimeinMinutes);
        AverageSpeed (milesfrombefore, milesleft, CurrenttimeinHour, CurrenttimeinMinutes, PastTimeinHours, PastTimeinMinutes, averagespeed);
        TimeEstimatefromhere(CurrenttimeinHour, CurrenttimeinMinutes, milesleft, TimestimatecalculatedHours, TimestimatecalculatedMinutes, averagespeed);
        ETA(TimestimatecalculatedHours, TimestimatecalculatedMinutes, CurrenttimeinHour, CurrenttimeinMinutes, TimeETAHour, TimeETAMinute);
        Showingoffdata (CurrenttimeinHour, CurrenttimeinMinutes, averagespeed, googlehours, googleminutes, TimestimatecalculatedHours, TimestimatecalculatedMinutes, TimeETAHour, TimeETAMinute);
    }
}
