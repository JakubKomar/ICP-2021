ICP projekt 2021-varianta 2
Editor a interpret hierarchicky strukturovaných funkčních bloků
Autors: Jakub Komárek (xkomar33),Violeta Koleva (xkolev00)


Nápověda:
Na začátku vytvořte aplikaci novou nebo ji načtěte z katalogu.
Spojení vytváříte kliknutím na port a tažením na další port. Vymazání spojení provádíte stejným způsobem jako při vytvoření(potáhnete myší) .
Vstup do editoru jednotlivých portů provedete stisknutím pravého tlačítka.
Vymazání bloku se provede zmáčknutím prostředního tlačítka myši (zmáčknutí kolečka).

uživatel má plnou kontrolu nad programem, provádí se pouze základní kontroly integrity.
Názvy portů nesmí být prázdné a v daném bloku nesmí být duplicitní-v atomických blokách se na ně odkazujete názvem portu->v interpretovaném kódu budu mít za následek chyby v překladu. Porty musí být pojmenovány podle konvecí zavedených pro proměnné v c++.
Jména bloků můžete volit libovolně. Id se můžou při načtení ze souboru změnit.
Pokud v kódu požijete některé knihovny/moduly neobsahující standart c++, musíte po vygenerování kódu tyto knihovny manuálně připsat.

Omezení:
Snažili jsme se program co nejvíce odladit nicméně za určitých velmi specifických podmínek program havaruje. Prosíme omluvte toto příležitostné chování.
Sabotování a úmyslné poškození souborů povede ke špatnému a nekoreknímu načtení, v extrémním případě povede i na pád aplikace.
