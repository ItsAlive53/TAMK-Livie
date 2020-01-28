# Ohjelman modularisointi

Modularisointi on ohjelmointitapa, jossa tavoitteena on paloitella ohjelmaa pienempiin, helposti uudelleenkäytettäviin osiin, jotta sitä voidaan hyödyntää myös myöhemmissä ohjelmissa, tai monessa paikassa samassa ohjelmassa. Siitä on myös hyötyä laajemmissa projekteissa, jos on monta työstämässä samaa ohjelmaa kerralla, he voivat ohjelmoida eri palasia kerrallaan, ja säästytään monelta ongelmalta mitä ryhmissä helposti syntyy, esim. monta muokkaamassaa samaa tiedostoa, vaikka olisi erittäin erilaiset osat ohjelmasta työn alla.

# Funktion esittely

Funktion esittelyssä määritetään funktion prototyyppi, joka kertoo kääntäjälle, että tämän niminen funktio on olemassa, sillä on tällainen palautusarvon tyyppi, ja nämä parametrit, mutta ei vielä mitä funktio varsinaisesti tekee

# Funktion toteutus

Funktion toteutuksessa taas kerrotaan kääntäjälle suoraan mitä esitelty funktio tekee, kun se ajetaan. Toteutukseen siis tulee varsinainen lähdekoodi, joka pyörii kun funktiota kutsutaan muualla. Joskus toteutus on myös suoraan esittelyn mukana, mutta monesti ne voidaan erotella, ja silloin esittelyt tehdään header-tiedostoon. esim .h tai .hpp, ja toteutus normaaliin lähdekooditiedostoon, esim. .cpp.

