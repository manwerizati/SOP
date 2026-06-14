Zadania do laboratorium 6 SOP
=============================

[](#-zadanie-1--trzy-procesy-potomne)✅ Zadanie 1 – Trzy procesy potomne
-----------------------------------------------------------------------

Napisz program, który:

*   Tworzy **trzy procesy potomne** (`fork()`).
*   Każdy proces potomny powinien:
    *   wypisać swój `PID` i `PPID`,
    *   zakończyć działanie kodem `exit(i)` (gdzie `i` to numer procesu).
*   Proces rodzica powinien:
    *   poczekać na **każdego potomka osobno** (`waitpid()`),
    *   wypisać informacje o zakończeniu dzieci: `PID` + kod wyjścia (`WEXITSTATUS()`).

* * *

[](#-zadanie-2--fork-i-identyfikacja-procesu)✅ Zadanie 2 – `fork()` i identyfikacja procesu
-------------------------------------------------------------------------------------------

Napisz program, który:

*   Tworzy jeden proces potomny.
*   Dziecko:
    *   wypisuje swój `PID` i `PPID`,
    *   śpi 2 sekundy,
    *   sprawdza ponownie `PPID` (czy zmienił się na 1),
    *   kończy działanie.
*   Rodzic kończy się **od razu**, bez `wait()`. ❓Czy rodzic się zmienia? Jeśli tak, to kto jest nowym rodzicem?

* * *

[](#-zadanie-3--dwa-procesy-potomne-z-kolejnością)✅ Zadanie 3 – Dwa procesy potomne z kolejnością
-------------------------------------------------------------------------------------------------

Napisz program, który:

*   Tworzy dwa procesy potomne.
*   Proces 1:
    *   wypisuje “Jestem procesem 1”,
    *   kończy się po 1 sekundzie.
*   Proces 2:
    *   czeka 2 sekundy,
    *   wypisuje “Jestem procesem 2”,
    *   kończy się.

Rodzic powinien użyć `waitpid()` i wypisać, **który proces zakończył się jako pierwszy i drugi**.

🎯 Możesz dodać timestamp (`time()` lub `gettimeofday()`), by precyzyjnie zmierzyć czas zakończenia.

* * *

[](#-zadanie-4--dziecko-czeka-na-inny-proces)✅ Zadanie 4 – Dziecko czeka na inny proces
---------------------------------------------------------------------------------------

Napisz program, który:

*   Tworzy dziecko.
*   Dziecko tworzy **swoje dziecko** (czyli wnuka).
*   Proces wnuka:
    *   wypisuje “Wnuk działa”, śpi 2 sekundy, kończy się `exit(5)`.
*   Proces dziecko:
    *   czeka na zakończenie wnuka (`wait()`),
    *   wypisuje `PID` zakończonego procesu i `WEXITSTATUS`.
*   Proces rodzic:
    *   nie czeka na nikogo i kończy się od razu.

* * *

[](#-zadanie-5-drzewo-procesów)✅ Zadanie 5– Drzewo procesów
-----------------------------------------------------------

Stwórz program, który buduje strukturę:

    Rodzic
    ├── Dziecko 1
    │   └── Wnuk 1
    └── Dziecko 2
        └── Wnuk 2
    

Każdy proces powinien wypisać swoje:

*   `PID`, `PPID`, poziom w drzewie
*   nazwę roli (np. “Dziecko 1”)