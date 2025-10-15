## Aufgabe 2.1
Beschreiben Sie die nicht funktionalen Anforderungen an ein Betriebssystem! Leiten Sie daraus Anforderungen an die Architektur des Betriebssystems ab!
- Stabilität
- Sicherheit
- Performance
- Bedienbarkeit
- Funktionalität
- Rückwärtskompatibilität

Für die Architekturen bedeutet das:

|                         | Monolith                     | Schichten | Microkernel | Client Server |
| ----------------------- | ---------------------------- | --------- | ----------- | ------------- |
| Leistung                | X                            |           |             |               |
| Sicherheit              |                              | X         |             |               |
| Stabilität              |                              |           | X           |               |
| Bedienbarkeit           |                              | X         |             |               |
| Rückwärtskompatibilität | ? (führt zu großer Codebase) |           |             |               |
| Wartbarkeit             |                              | X         |             |               |
| Erweiterbarkeit         |                              | X         |             |               |

## Aufgabe 2.2
Bestimmen Sie den Pfad ihres HOME-Verzeichnisses
```sh
$ echo $HOME
/home/maik
```

Lassen Sie sich den Inhalt ihres Verzeichnisses in kurzer und ausführlicher Form anzeigen!
```sh
$ ls
$ ll  # oder ls -l
```

Mit und ohne „hidden“ Files
```sh
$ ls
$ ls -a
```
## Aufgabe 2.3
Bestimmen Sie was in der Datei `name.txt` steht! 
```sh
$ cat namen.txt
Manuel Neuer
Marc-Andre ter Stegen
Ron-Robert Zieler
Holger Badstuber
Howard Wolowitz
Jérôme Boateng
Philipp Lahm
Mats Hummels
Rajesh Koothrappali
Per Mertesacker
Benedikt Höwedes
Marcel Schmelzer
Julian Draxler
Leonard Hofstadter
Lukas Podolski
Sami Khedira
Toni Kroos
Mesut Özil
Thomas Müller
Marco Reus
Bastian Schweinsteiger
Andre Schürrle
Mario Götze
Sven Bender
Sheldon Cooper
Ilkay Gündogan
Lars Bender
Mario Gomez
Miroslav Klose
```

Welches ist der erste Name?
```sh
$ head -1 namen.txt
Manuel Neuer
```

Welcher ist der letzte Name? (vorausgesetzt letzte Zeile ist nicht blank)
```sh
$ tail -1 namen.txt
```

Sortieren Sie die Datei in aufsteigender alphabetischer Reihenfolge (sort)!
```sh
$ sort namen.txt -o namen-sorted.txt
```

Welche Option kehrt die Ausgabe in absteigender alphabetischer Reihenfolge um?
```sh
$ sort namen.txt -o namen-sorted-reverse.txt -r
```

Wie viele Zeilen, Wörter und Zeichen enthält die Datei?
```sh
$ wc namen.txt
 30  59 446 namen.txt
```

Bestimmen Sie wie häufig ein Doppel-o („oo“) in der Datei vorkommt!
```sh
$ grep "oo" namen.txt
Rajesh Koothrappali
Toni Kroos
Sheldon Cooper
```

Speichern Sie alle Personen mit einem Doppel-o im Namen in eine Datei „oo.txt“!
```sh
$ grep "00" namen.txt > oo.txt
```

Bei jeder der oberen Befehle muss das Betriebssystem zunächst die Datei öffnen, anschließend den Inhalt der Datei als Bytestrom auslesen (entweder komplett oder solange, bis der entsprechende Filter erfolgt ist) und danach ggf. eine Operation auf dem gegebenen Inhalt ausführen. Falls der Inhalt modifiziert wurde, muss der neue Inhalt ggf. wieder in die Datei zurückgeschrieben und anschließend der Bytestrom geschlossen werden.
## Aufgabe 2.4
Wo liegt die `libc.a` Datei nach der Installation des `gcc`-Compilers?
```sh
$ sudo find /usr -name "libc.a"
/usr/lib64/libc.a
```

Wie viele Wrapperfunktionen sind in der Bibliothek enthalten?
```sh
$ ar -t /usr/lib64/libc.a | wc -l
2209
```

Sind die Funktionen `fork.o` und `creat.o` auch enthalten?
```sh
$ ar -t /usr/lib64/libc.a | grep -w -n "fork.o"
1281:fork.o

$ ar -t /usr/lib64/libc.a | grep -w -n "creat.o"
1399:creat.o
```
