## Aufgabe 9.1
> Systeme, die sequentielle Dateien unterstützen, haben immer auch eine Operation, um diese zurückzuspulen.
>
> Benötigen Systeme, die Dateien mit wahlfreiem Zugriff unterstützen, diese Operation auch?

Beim random access ist das unnötig, da wir ohnehin an jeden Punkt der Datei springen können.

## Aufgabe 9.2
> Um zu vermeiden dass ein Datenträger viele frei Lücken enthält, könnte der Datenträger jedes Mal verdichtet, wenn eine Datei entfernt wird. Da alle Dateien zusammenhängend sind, benötigt das Kopieren einer Datei einen Plattenzugriff (5ms) und eine rotationsbedingte Wartezeit (4ms). Danach läuft Datenübertragung mit voller Geschwindigkeit (8MB/s). Die durchschnittliche Dateigröße beträgt 8 KB.
> 
> Wie lange würde es dauern die Hälfte einer 16 GB Festplatte zu verdichten?

Anzahl Dateien: $\dfrac{8589934592~\text{B}}{8192~\text{B}} = 1048576$

Zeit pro Datei: $5~\text{ms} + 4~\text{ms} + \dfrac{8192\text~{B}}{8388608 \frac{B}{s}} \approx 10~\text{ms}$
Zeit insgesamt: $1048576 \cdot 0.01~\text{s}=10485.76~\text{s}=174.762~\text{m}=2.912~\text{h}$
(Zeit mal zwei rechnen, da Lesen und Schreiben jeweils so lang brauchen)

> Diskutieren Sie anhand des Ergebnisse, ob eine Verdichtung von Plattenplatte dann überhaupt sinnvoll ist!

Die Verdichtung ist durchaus sinnvoll, wenn die Fragmentierung sehr weit fortgeschritten ist und die Daten „kreuz und quer“ liegen. Da der Prozess aber zeitaufwändig ist, sollte man das nicht bei jedem Löschen einer Datei.

## Aufgaben 9.3
> Ein einfaches Betriebssystem unterstützt nur ein Verzeichnis, dieses kann aber beliebig viele Dateien aufnehmen. Kann etwas Ähnliches wie ein hierarchisches Dateisystem realisiert werden? Wenn ja, wie? Können Sie auch Metadaten über ein Verzeichnis speichern?

Man könnte Dateinamen mit einem „Ordnernamen“ präfixen, bspw. `.Rechnungen_A.xlsx`, `Rechnungen_B.xlsx`, usw.

Metadaten über ein Verzeichnis könnte man ebenfalls in einer Datei, bspw `.DIR_INFO`speichern.

## Aufgabe 9.4
> Ein UNIX Dateisystem hat 512 Byte-Blöcke und 4 Byte Plattenadressen. Was ist die die maximale Dateigröße, falls die I-Nodes zehn direkte Einträge und jeweils einen einfach, doppelt und dreifach indirekten Eintrag besitzen?

max. Anzahl Pointer pro Block: $\dfrac{512~\text{B}}{4~\text{B}} = 128$
Anzahl direkte Einträge: $10$
max. Anzahl Pointer in einfach indirekte Einträge: $1 \cdot 128$
max. Anzahl Pointer in zweifach indirekte Einträge: $1 \cdot 128^2$
max. Anzahl Pointer in dreifach indirekte Einträge: $1 \cdot 128^3$
max. Anzahl Pointer insgesamt: $10+128+128^2+128^3=2113674$

max. Größe pro Datei: $2113674\cdot 512~\text{B}=1.082.201.088~\text{B}\approx 1~\text{GB}$

## Aufgabe 9.5
> In dem vorgestellten INode-Model speichert die INode Attribute und Zeiger auf Blöcke. Die eigentlichen Daten befinden sich in den Blöcken. Welche Vorteile hätte es, wenn der erste Teil jeder UNIX-Datei auch im selben Block wie die INode gespeichert würde?

Der Vorteil wäre, dass wir, wenn wir mit dem Lesekopf der Festplatte zum Beginn der Datei springen, dass wir neben den Metadaten auch direkt den ersten Datenblock haben, ohne in der I-Node Tabelle erstmal nach der Adresse für den ersten Plattenblock so suchen.

## Aufgabe 9.6
> Was passiert, wenn bei einem Systemabsturz die Freibereichslisten oder Bitmaps mit den Informationen über freie Blöcke verloren gehen?
> 
> Gibt es einen Weg die Daten zu retten oder sind diese für immer verloren?
> 
> Diskutieren Sie Ihre Antwort separat für UNIX und FAT-16!

Das System müsste die gesamte Festplatte von vorne bis hinten durchlaufen und die Liste komplett neu aufbauen, was sehr ressourcenaufwendig ist. Unter Unix gibt es dafür das Programm `fsck`, auf Windows gibt es `scandisk`.

Sofern die Liste der belegten Blöcke noch existiert, sind die Daten nicht verloren. Es muss lediglich die Freibereichsliste rekonstruiert werden.

## Aufgabe 9.7: Link
> Die meisten Betriebssysteme unterscheiden zwischen harten und weichen Links/Verweisen auf Dateien. Führen Sie unter Linux (Befehl ln) die folgenden beiden Aufgaben durch. 

> Notieren Sie die verwendeten Befehle:
> 1. Symbolische Links
	1. Erzeugen Sie zwei Verzeichnisse mit den Namen „Original“ und „Kopie“.
	2. Wechseln Sie in das Verzeichnis Original und erzeugen eine Datei „original.txt“ mit dem Inhalt „Ich bin das Original“.
	3. Wechseln Sie nun in das Verzeichnis „Kopie“ und erzeugen einen soft/weichen/symbolischen Link auf die Datei original.txt. Der neue Link soll den Namen „symlink_original.txt“ haben.
	4. Kopieren Sie die Datei „original.txt“ in das Verzeichnis Kopie.
	5. Lassen Sie sich die Details der Dateien ausgeben!
	6. Geben Sie den Inhalt aller Dateien im Verzeichnis „Kopie“ aus.
	7. Löschen Sie nun die Datei „Original/original.txt“
	8. Geben Sie nochmal den Inhalt aller Dateien im Verzeichnis aus.
	9. Notieren Sie das Ergebnis
> 2. ⁠ ⁠Hardlink
	1. Erzeugen Sie zwei Verzeichnisse mit den Namen „Original“ und „Kopie“.
	2. Wechseln Sie in das Verzeichnis Original und erzeugen eine Datei „original.txt“ mit dem Inhalt „Ich bin das Original“.
	3. Wechseln Sie nun in das Verzeichnis „Kopie“ und erzeugen einen harten Link auf die Datei original.txt. Der neue Link soll den Namen „hardlink_original.txt“ haben.
	4. Kopieren Sie die Datei „original.txt“ in das Verzeichnis Kopie.
	5. Lassen Sie sich die Details der Dateien ausgeben!
	6. Geben Sie den Inhalt aller Dateien im Verzeichnis „Kopie“ aus.
	7. Löschen Sie nun die Datei „Original/original.txt“
	8. Geben Sie nochmal den Inhalt aller Dateien im Verzeichnis aus.
	9. Notieren Sie das Ergebnis

Symbolische Links:
```sh
$ mkdir original
$ mkdir kopie
$ cd original && echo "Ich bin das Original" > original.txt
$ cd ../kopie && ln -s ../original/original.txt sym-link_original.txt
$ cp ../original/original.txt ./original.txt
$ stat original.txt
16777234 10776498 -rw-r--r-- 1 maik staff 0 21 "Dec  1 16:59:52 2025" "Dec  1 16:59:50 2025" "Dec  1 16:59:50 2025" "Dec  1 16:59:50 2025" 4096 8 0 original.txt

$ stat sym-link_original.txt
16777234 10776072 lrwxr-xr-x 1 maik staff 0 24 "Dec  1 16:57:29 2025" "Dec  1 16:57:29 2025" "Dec  1 16:59:32 2025" "Dec  1 16:57:29 2025" 4096 0 0 sym-link_original.txt

$ rm -f ../original/original.txt
$ cat sym-link_original.txt
cat: sym-link_original.txt: No such file or directory

$ cat original.txt
Ich bin das Original
```

Hardlinks:
```sh
setup wie oben
$ ln ../original/original.txt sym-link_original.txt
$ stat original.txt
16777234 10779120 -rw-r--r-- 1 maik staff 0 21 "Dec  1 17:20:06 2025" "Dec  1 17:20:04 2025" "Dec  1 17:20:04 2025" "Dec  1 17:20:04 2025" 4096 8 0 original.txt

$ stat hardlink_original.txt
16777234 10778414 -rw-r--r-- 2 maik staff 0 21 "Dec  1 17:19:51 2025" "Dec  1 17:14:58 2025" "Dec  1 17:19:50 2025" "Dec  1 17:14:58 2025" 4096 8 0 hardlink_original.txt

$ rm -f ../original/original.txt
$ cat hardlink_original.txt
Ich bin das Original

$ cat original.txt
Ich bin das Original
```

> Was stellen Sie fest? Geben Sie eine Erklärung für das unterschiedliche Verhalten.
> 
> Welche Schritte laufen im Hintergrund ab.

Der symlink ist der Pointer auf eine Datei, die bestimmte Daten beinhaltet. Wenn wir diese Datei löschen, verweist der symlink ins leere (da die Datei nicht mehr existiert). Ein hardlink ist eine separate Datei, die jedoch auf die gleichen Daten wie die originale Datei verweist. Wenn die originale Datei nun gelöscht wird, bleiben die Daten bestehen und der hardlink kann als „seperate Tür“ weiterhin genutzt werden.