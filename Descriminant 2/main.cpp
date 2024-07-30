//
//  Determinant.cpp
//  Descriminant
//
//  Created by Aniket Sedhai on 6/26/24.
//

#include <iostream>
#include <iomanip>
#include <string>

template <typename T>

T Descriminant(T a, T b, T c)
{
    T Descriminant = b * b - 4.0 * a * c;

    if (Descriminant < 0)
    {
        throw std::exception("Discriminant(a, b, c): Negative Discriminant Encountered");
    }

    return Descriminant;
}

int main(void)
{
    bool dont_abort_calculation;
    bool invalid_entry;

    char user_answer;
    do
    {
        dont_abort_calculation = false;

        try
        {
            double a_val;
            double b_val;
            double c_val;

            std::cout << "Provide the following values: " << std::endl;
            std::cout << " a = ";
            std::cin >> a_val;
            std::cout << std::endl << " b = ";
            std::cin >> b_val;
            std::cout << std::endl << " c = ";
            std::cin >> c_val;


            double det = Descriminant(a_val, b_val, c_val);

            std::cout << "The descriminant is: " << det << std::endl;
        }

        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }

        do
        {
            invalid_entry = false;
            std::cout << "Do you want to calculate more descriminant? (Y/y/N/n): ";
            std::cin >> user_answer;

            if ((user_answer == 'Y') || (user_answer == 'y'))
            {
                dont_abort_calculation = true;
            }
            else if ((user_answer == 'N') || (user_answer == 'n'))
            {
                dont_abort_calculation = false;
            }
            else
                invalid_entry = true;
        } while (invalid_entry);

    } while (dont_abort_calculation);

    return 0;
}
