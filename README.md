# TicTacToe-Extreme
 TicTacToe but Xtreme - An ITA21 Cpp Project


----

In diesem Projekt wurde eine Extreme Version von TicTacToe programmiert - das extreme daran ist, dass so viele Spieler wie gewünscht gegeneinander auf einem Spielfeld spielen können, dessen größe nach belieben erweiterbar ist. Ansonsten sind die Spielregeln die gleichen wie bei dem klassischen TicTacToe: Man gewinnt sobald man drei gleiche Symbole in einer Reihe verbinden kann.

- Programmbeschreibung:

Der GameManager ist das Herzstück des Programms und steuert das Spielgeschehen. Hier wird von der Main die startGame() Funktion aufgerufen. Dadurch wird die Anzahl der Spieler abgefragt und im Anschluss welchem Typ Spieler diese angehören. Diese Spieler mit ihren Namen, Typen und ihrem Symbol werden in einer Liste gespeichert und später weitergegeben.
Man kann auswählen zwischen:

- human: Also normalen menschlichen Spieler
- randomBot: Dieser setzt an zufälligen Plätzen sein Symbol
- smartBot: Dieser blockt falls ein gegnerischer Spieler gewinnen könnte und gewinnt wenn er schon zwei Symbol in einer Reihe hat

Als nächstes wird die Funktion runningGame aufgerufen, diese wird rekursiv aufgerufen bis das Spielfeld voll ist oder ein Spieler drei Symbole in einer Reihe gesetzt hat. Dabei looped runningGame durch die Spielerliste durch und lässt die Spieler je nach Typen die Spielzüge machen. Hier wird auch der InputHandler verwendet, dieser kann eine Eingabe von einer Ranger weitergeben oder einen String mit Hilfe einer Spieleranweisung annehmen. 

In der Funktion von runningGame wird auch eine Instanz von Playboard initialisiert, diese besteht aus zwei verschachtelten Vectoren und stellt über printPlayboard das Spielfeld grafisch dar. Wenn ein Symbol gesetzt wird, ersetzt dieses ein leeres Feld, dabei beginnen die Symbole für Spieler 1 und 2 mit x und o, darauf folgt für die kommenden Spieler die ASCII Reihe ab a(,b,c,d,...).

Spielerweiterungen:

- Wenn mehr Spieler spielen sollen als es überhaupt Felder gibt wird dies verboten
- Wenn weiter SpielerTypen hinzugefügt werden wollen, kann einfach das enum der Spielertypen erweitert werden und anschließend muss die makeMove Funktion erstellt und im switchCase bei dem jeweiligen Spielertyp eingebracht werden. Dadurch ist eine Erweiterung von neuen Spielertypen sehr einfach.

