## Aufgabe 2.1
> Beschreiben Sie die nicht funktionalen Anforderungen an ein Betriebssystem! Leiten Sie daraus Anforderungen an die Architektur des Betriebssystems ab!
- Stabilität
- Sicherheit
- Performance

## Aufgabe 2.2
> Bestimmen Sie den Pfad ihres HOME-Verzeichnisses
```
$ echo $HOME
/home/maik
```

> Lassen Sie sich den Inhalt ihres Verzeichnisses in kurzer und ausführlicher Form anzeigen!
```
$ ls
$ ll
```

> Mit und ohne „hidden“ Files
```
$ ls
$ ls -a
```
## Aufgabe 2.3
> Bestimmen Sie was in der Datei name.txt steht! 
```
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

> Welches ist der erste Name?
```
$ head -1 namen.txt
Manuel Neuer
```

> Welcher ist der letzte Name? (vorausgesetzt letzte Zeile ist nicht blank)
```
$ tail -1 namen.txt
```

> Sortieren Sie die Datei in aufsteigender alphabetischer Reihenfolge (sort)!
```
$ sort namen.txt -o namen-sorted.txt
```

> Welche Option kehrt die Ausgabe in absteigender alphabetischer Reihenfolge um?
```
$ sort namen.txt -o namen-sorted-reverse.txt -r
```

> Wie viele Zeilen, Wörter und Zeichen enthält die Datei?
```
$ wc namen.txt
 30  59 446 namen.txt
```

> Bestimmen Sie wie häufig ein Doppel-o („oo“) in der Datei vorkommt!
```
$ grep "oo" namen.txt
Rajesh Koothrappali
Toni Kroos
Sheldon Cooper
```

> Speichern Sie alle Personen mit einem Doppel-o im Namen in eine Datei „oo.txt“!
```
$ grep "00" namen.txt > oo.txt
```