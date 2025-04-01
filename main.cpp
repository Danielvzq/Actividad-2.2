
/*
 * SonarQube, open source software quality management tool.
 * Copyright (C) 2008-2013 SonarSource
 * http://github.com/SonarOpenCommunity/sonar-cxx
 *
 * SonarQube is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * SonarQube is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Estructura para almacenar sufijos
struct Suffix
{
    string suffix;
    int index;
};

// Función para comparar sufijos
bool compare(const Suffix &a, const Suffix &b)
{
    return a.suffix < b.suffix;
}

// Función principal
int main()
{
    // Se solicita al usuario una cadena
    string input;
    cout << "Introduce cadena: "; // Mensaje agregado
    getline(cin, input);

    // Se almacenan los sufijos de la cadena
    vector<Suffix> suffixes;

    for (size_t i = 0; i < input.size(); ++i)
    {
        suffixes.push_back({input.substr(i), static_cast<int>(i + 1)});
    }

    // Se ordenan los sufijos
    sort(suffixes.begin(), suffixes.end(), compare);

    for (const auto &s : suffixes)
    {
        cout << s.index << "\n";
    }

    return 0;
}

