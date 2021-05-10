ICP projekt 2021-varianta 2
Editor a interpret hierarchicky strukturovaných funkčních bloků
Autors: Jakub Komárek (xkomar33),Violeta Koleva (xkolev00)


Nápověda:
Při zpuštění vytvořte aplikaci novou nebo ji načtěte z katalogu. Do té doby nelze vytvářet bloky.
Spojení vytváříte kliknutím na port a tažením na další port. Vymazání spojení provádíte stejným způsobem jako při vytvoření(potáhnete myší ) .
Vstup do editoru jednotlivých portů provedete stisknutím pravého tlačítka na bloku.
Vymazání bloku se provede zmáčknutím prostředního tlačítka myši (zmáčknutí kolečka).
Změna jména bloku a změna kódu je podmíněna stisknutím ukládacího tlačítka.
Jména bloků můžete volit libovolně. Id se můžou při načtení ze souboru změnit.
Pokud v kódu požijete některé knihovny/moduly neobsahující standart c++ nebo knihovny neobsažené v hlavičce, musíte po vygenerování kódu tyto knihovny manuálně připsat.
Názvy portů nesmí být prázdné a v daném bloku nesmí být duplicitní-v atomických blokách se na ně odkazujete názvem portu->stejně pojmenované porty v interpretovaném kódu budu mít za následek chyby v překladu. Porty musí být pojmenovány podle konvecí pro proměnné v c++.

Katalog:
V levém sloupci vybíráte kategorii, v pravém vybíráte konkrétní blok.
Pro načtení z katalogu zmáčkněte tlačítko load, načtení bloku/aplikace provádíte dvojklikem nad blokem v katalogu(pravá část aplikace). Pokud vyberete aplikaci, předchozí aplikace se nenávratně smaže. 
Pro uložení bloku stiskněte tlačítko save. Ukládá se vždy právě zobrazovaná instance. V katologu provedete uložení dvojklikem na kategorii (levá část aplikace)

uživatel má plnou kontrolu nad programem, provádí se pouze základní kontroly integrity.




Omezení:
Sabotování a úmyslné poškození souborů povede ke špatnému a nekoreknímu načtení, v extrémním případě povede i na pád aplikace.
Snažili jsme se program co nejvíce odladit nicméně za určitých velmi specifických podmínek program může havarovat. Prosíme omluvte toto příležitostné chování.
