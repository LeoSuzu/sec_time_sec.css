//
// Created by Leo Suzuki on 25.1.2023.
// Basic time value changing program. Menu 5 different functions.
//

#include <iostream>
#include <iomanip>
using namespace std;

// Making structure
struct Time{
    int hour;
    int mins;
    int secs;
};

// Introdusing fuction
void seconds_to_time(int seconds, int *s_p, int *m_p, int *h_p);
int  time_to_seconds(int s, int m, int h);
Time time_difference(Time t1, Time t2);
int h_taker_time();
int s_m_taker_time();

int main()

{
    // variables
    int seconds, *s_p, minutes, *m_p, hours, *h_p, choice;

    // Time variables
    Time t1, t2, diff;

    cout << "Difference = "<< diff.hour << ":" << diff.mins << ":" << diff.secs;

    // Creating dtata pointers
    s_p = &seconds;
    m_p = &minutes;
    h_p = &hours;


    cout << "Anna muutettava aikamuoto: \n";
    cout << "1. sekunnit aikamuotoon tunteja, minuutteja ja sekunteja \n";
    cout << "2. Tunnit, minuutit, ja sekunnit sekunteiksi \n";
    cout << "3. Asetetaan kellon aika ja näytetään sekunteina\";\n";
    cout << "4. Vetaa kellonaikojen erotus \n";
    cout << "5. Lopeta ohjelma \n";


    while (choice != 5)
    {
        cout << "Valitse 1, 2, 3, 4, 5: ";
        cin >> choice;
        switch(choice)
        {
            case 1:

                // User input
                cout << "Anna muutettava aika sekunteina \n";
                cin >> seconds;

                // Function call
                seconds_to_time(seconds, s_p, m_p, h_p);

                cout << seconds <<" sekuntia vastaava aika tunteina, minuutteina ja sekunteina on" << endl;
                // Printing results
                cout << hours << " tuntia, " << minutes << " minuuttia ja " << seconds << " sekuntia ja" << endl;
                cout << *h_p << ":" << *m_p << ":" << *s_p <<endl;

                // Function call to change hours, minutes, seconds back to seconds;
                seconds = time_to_seconds(seconds, minutes, hours);
                cout << "vastaavasti kokonaissekuntimäärä on: " << seconds << endl;
                break;

            case 2:

                // User input
                cout << "Anna muutettavt tunnit \n";
                // Validate user input and store to value
                hours = h_taker_time();
                cout << "Anna muutettava aika minuutteina \n";
                minutes = s_m_taker_time();
                cout << "Anna muutettava aika sekunteina \n";
                seconds = s_m_taker_time();

                // Print before change values
                cout << hours << " tuntia, " << minutes << " minuuttia ja " << seconds << " sekuntia joka on puolestaan ";

                // Function call to value change
                seconds = time_to_seconds(seconds, minutes, hours);

                // Printing results
                cout<< seconds << " sekuntia \n";
                break;

            case 3:

                cout << "Asetetaan kellon aika";
                cout << "Anna tunnit ";
                // Validate user input and store to value
                t1.hour = h_taker_time();
                cout << "Anna minuutit ";
                t1.mins = s_m_taker_time();
                cout << "Anna tunnit ";
                t1.secs = s_m_taker_time();
                cout << "Kello on asetettu aikaan: " << setfill('0') << setw(2) << t1.hour << ":" << setfill('0') << setw(2) << t1.mins << ":" << setw(2) << t1.secs << endl;
                seconds = time_to_seconds(t1.secs, t1.mins, t1.hour);
                cout<< " ja se on "<< seconds <<  " sekuntia \n";


                break;

            case 4:

                cout << "Aika 1 ";
                cout << "Anna tunnit 1 ";
                // Validate user input and store to value
                t1.hour = h_taker_time();
                cout << "Anna minuutit 1 ";
                t1.mins = s_m_taker_time();
                cout << "Anna sekunnit 1 ";
                t1.secs = s_m_taker_time();
                cout << "Aika 1 asetettu: " << setfill('0') << setw(2) << t1.hour << ":" << setfill('0') << setw(2) << t1.mins << ":" << setw(2) << t1.secs << endl;

                cout << "Asetetaan aika 2 ";
                // Validate user input and store to value
                cout << "Anna tunnit 2 ";
                t2.hour = h_taker_time();
                cout << "Anna minuutit 2 ";
                t2.mins = s_m_taker_time();
                cout << "Anna sekunnit 2 ";
                t2.secs = s_m_taker_time();

                // Print substraction between two times
                cout << "Vertailtavien kellonaikojen erotus on:\n";
                diff = time_difference(t1, t2);

                // Change it to scounds and print
                seconds_to_time(diff.secs, s_p, m_p, h_p);
                cout << hours << " tuntia, " << minutes << " minuuttia ja " << seconds << " sekuntia ja" << endl;
                cout << setfill('0') << setw(2) << *h_p << ":" << setfill('0') << setw(2) << *m_p << ":" << setfill('0') << setw(2) << *s_p << endl;

                break;

            case 5:
                // User choosed to quit program
                cout << "Kiitos käytöstä!\n";
                cout << "ohjelma on päättynyt";
                return 0;
            default:
                cout << "Valitse 1, 2 tai 3: ";
        }
    }


    return 0;
}

// Function collections

// Seconds to hh mm ss using pointer value to change func outside values
void seconds_to_time(int seconds, int *s_p, int *m_p, int *h_p) {
    *m_p = seconds / 60;
    *s_p = seconds % 60;
    *h_p = *m_p / 60;
    *m_p = *m_p % 60;
}

// hh mm ss to seconds with basic int input
int  time_to_seconds(int s, int m, int h)
{
    s = s + (m * 60) + (h * 3600);
    return s;
}

// Time difference calculator
Time time_difference(Time t1, Time t2)
{
    int t1_sec, t2_sec;
    Time diff;
    t1_sec = t1.secs + (t1.mins * 60) + (t1.hour * 3600);
    t2_sec = t2.secs + (t2.mins * 60) + (t2.hour * 3600);

    if(t1_sec > t2_sec)
    {
        diff.secs = t1_sec - t2_sec;
    }
    else
        diff.secs = t2_sec - t1_sec;

    return diff;

}

// Num validation function for hours
int h_taker_time()
{
    // Local variable
    bool is_range = true;
    int time;

    // Tarkistetaan mikäli ei ole syötetty numeroa
    while (is_range)
    {
        cout << "Syötä aika 0-24 välillä: ";
        cin >> time;
        if (!cin)
        {
            cout << "Et syöttänyt numeroita. Syötä numero uudelleen. " << endl;
            std::cin.clear(); // reset error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
            // Tarkistetaan virheiden varalta ja että numero on 1-300 välillä.
        else if ((time > 24) || (time < 0))
        {
            cout << "Syötä kokonaisnumero 0-24 välillä: " << endl;
            std::cin.clear(); // reset error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
            // Palauteaan arvo ja siirrytään varausfunktioon.
        else
        {
            is_range = false;
        }
    }

    return (time);
}

// Num validation function for hours
int s_m_taker_time()
{
    // Local variable
    bool is_range = true;
    int time;

    // Tarkistetaan mikäli ei ole syötetty numeroa
    while (is_range)
    {
        cout << "Syötä aika 0-59 välillä: ";
        cin >> time;
        if (!cin)
        {
            cout << "Et syöttänyt numeroita. Syötä numero uudelleen. " << endl;
            std::cin.clear(); // reset error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
            // Tarkistetaan virheiden varalta ja että numero on 1-300 välillä.
        else if ((time > 59) || (time < 0))
        {
            cout << "Syötä aika 0-59 välillä: " << endl;
            std::cin.clear(); // reset error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
            // Palauteaan arvo ja siirrytään varausfunktioon.
        else
        {
            is_range = false;
        }
    }

    return (time);
}

//EOF
