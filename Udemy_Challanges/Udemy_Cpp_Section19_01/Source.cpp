#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City 
{
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country
{
    std::string name;
    std::vector<City> cities;
};

struct Tours 
{
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
    { "Tour Ticket Prices from Miami",
        {
            {
                "Colombia", {
                    { "Bogota", 8778000, 400.98 },
                    { "Cali", 2401000, 424.12 },
                    { "Medellin", 2464000, 350.98 },
                    { "Cartagena", 972000, 345.34 }
                },
            },
            {
                "Brazil", {
                    { "Rio De Janiero", 13500000, 567.45 },
                    { "Sao Paulo", 11310000, 975.45 },
                    { "Salvador", 18234000, 855.99 }
                },
            },
            {
                "Chile", {
                    { "Valdivia", 260000, 569.12 },
                    { "Santiago", 7040000, 520.00 }
            },
        },
            { "Argentina", {
                { "Buenos Aires", 3010000, 723.77 }
            }
        },
    }
    };

    // Unformatted display so you can see how to access the vector elements

    const char* ruller = "1234567890123456789012345678901234567890123456789012345678901234567890";
    const int row_size{ 70 };
    const int field_width1{ 20 };
    const int field_width2{ 15 };

    std::cout << ruller << std::endl << std::endl;
    std::cout << std::setw(row_size / 2 + tours.title.length() / 2) << tours.title << std::endl << std::endl
        << std::setw(field_width1) << std::left << "Country"
        << std::setw(field_width1) << "City"
        << std::setw(field_width2) << std::right << "Population"
        << std::setw(field_width2) << "Price" << std::endl
        << std::setw(row_size) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');

    bool first_time{ true };
    std::cout << std::setprecision(2) << std::fixed;

    for (auto country : tours.countries) 
    {
        // loop through the countries
        std::cout << std::setw(field_width1) << std::left << country.name;
        
        for (auto city : country.cities) 
        {       
            // loop through the cities for each country
            if (!first_time)
                std::cout << std::setw(field_width1) << " ";
           
            std::cout << std::setw(field_width1) << std::left << city.name
                << std::right << std::setw(field_width2) << city.population
                << std::setw(field_width2) << city.cost
                << std::endl;

            first_time = false;
        }

        first_time = true;
    }

    std::cout << std::endl << std::endl;
}