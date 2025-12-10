## Aufgabe 11.1
> Nennen Sie die vier Ziele/Aufgaben eines Betriebssystems bezüglich der Sicherheit und mögliche Bedrohungen!

1. Vertraulichkeit (Vermeidung von Datenleaks)
2. Datenintegrität (Vermeidung von Datenmanipulation)
3. Authentizität (wegen Systemübernahme von Viren)
4. Verfügbarkeit (Vermeidung von Denial of Service)

## Aufgabe 11.2
> Betrachten Sie ein symmetrisches Verschlüsselungsverfahren, bei dem sich Sender und Empfänger in der Vergangenheit auf einen Schlüssel geeinigt hatten. Sie haben den Verdacht, dass der Schlüssel nicht mehr zuverlässig ist und wollen sich auf einen neuen Schlüssel einigen. Die beiden können sich nicht treffen, kennen aber eine vertrauenswürdige dritte Partei, die jeweils einen anderen Schlüssel mit Sender bzw. Empfänger teilt.
> 
> Wie können Sender und Empfänger unter diesen Umständen einen neuen geheimen Schlüssel teilen?

Person A könnte den Schlüssel generieren, an Person C schicken und Person C leitet diesen Schlüssel an B weiter. Wir gehen davon aus, dass die Kommunikationswege sicher sind und das einzige Risiko wäre, dass Person C den Schlüssel weitergibt.

Unabhängig davon wäre es allgemein sicherer den Schlüsselaustausch nach dem Diffie-Hellmann-Verfahren durchzuführen, da so selbst über einen unsicheren Weg sicher der Schlüssel ausgetauscht werden kann.

## Aufgabe 11.3
> In einem System sind zu einen Zeitpunkt 1000 Objekte und 100 Domänen. Zum Ablegen einer Objekt-ID, einer Domänen-ID und der Zugriffsrechte (z.B. r-w-x Kombination) wird jeweils eine Speicherplatzeinheit benötigt.

-  Auf 1% der Objekte kann in allen Domänen zugegriffen werden. ($10\cdot 100$)
-  Auf 10% der Objekte kann in zwei Domänen nicht zugegriffen werden. ($100\cdot 98$)
-  Auf die restlichen Domänen (89%) kann nur in einer Domäne zugegriffen werden. ($890\cdot 1$)

> Wie viel Platz (in Speicherplatzeinheiten) wird benötigt, wenn man

- Die Schutzmatrix als ganzes abspeichert
  $1000\cdot 100\cdot 1~\text{SE}$
-  Die Schutzmatrix als Zugriffskontrolllisten abspeichert?
   $11960\cdot 2~\text{SE}$
-  Die Schutzmatrix als Capability-Listen abspeichert?
   $11960\cdot 2~\text{SE}$

## Aufgabe 11.4
> Das folgendes Verzeichnis mit vier Dateien ist in einem System vorhanden.
```bash
-rw-r----- 2 bob   users 908   May,23-17:52 PPP-Notes
-rwxr-x--- 1 alice devel 432   May,28-09:40 prog1
-rw-rw---- 1 alice users 50094 May,30-17:51 project.t
-rw-r----- 1 alice devel 13124 May,31-12:31 splash.gif
```

> Der Benutzer alice ist Mitglied in den Gruppen users und devel.
> Der Benutzer bob ist nur Mitglied in der Gruppe users.
	• Behandeln sie die beiden Benutzer und die beiden Gruppen als Domänen, so dass sie bei 4 Dateien eine 4x4 Schutzmatrix erhalten.
	• Erstellen Sie die Schutzmatrix für das Verzeichnis!
	• Erstellen Sie dann die Zugriffskontrolllisten für das Verzeichnis!

|       | PPP-Notes | prog1 | project.t | splash.gif |
| ----- | --------- | ----- | --------- | ---------- |
| alice | r         | r/w/x | r/w       | r/w        |
| bob   | r/w       | none  | r/w       | none       |
| users | r         | none  | r/w       | none       |
| devel | none      | r/x   | none      | r          |

## Aufgabe 11.5
> Bei vielen Windows-Systemen haben ausgewählte Benutzer die Möglichkeit temporär Administratorrechte zu erhalten. Erklären Sie wieso dies gegen das POLA Prinzip für Sicherheit verstößt!

Wenn ein User temporär mehr Rechte benötigt, als er aktuell hat, wäre der „richtige“ Weg ihm auch nur die Rechte zu geben, die er nun zusätzlich braucht und nicht temporär „alles“. Allerdings ist es in der Praxis einfacher und ressourcensparender, da nicht erst herausgefunden werden muss, welche Rechte er nun genau braucht.