## Aufgabe 3.1
Beschreiben Sie die wesentlichen Unterschiede zwischen Programm und Prozess.

> Ein Programm ist eine Menge an Instruktionen, ein Prozess ist ein Programm, das ausgeführt wird.

## Aufgabe 3.2
Erzeugen Sie zwei Hintergrundprozesse. Jeder dieser Prozesse soll eine bestimmte Anzahl von Sekunden lang nichts tun (siehe sleep), dann eine Meldung ausgeben („Hier Prozess 1“ bzw. „Hier Prozess 2“), dann nochmals dieselbe Zeit schlafen und zum Abschluss nochmals die Meldung ausgeben.

Schreiben Sie dazu ein Shellscript, das mit der Kennziffer und den Sekundenzahlen
parametrisiert ist und das Sie zweimal aufrufen.
-  Geben Sie den Prozessstatus des Systems aus, während die Prozesse schlafen (siehe pr)
-  Beenden Sie einen Prozess vorzeitig (siehe kill)
-  Starten Sie einen Hintergrundprozess, der seinerseits drei neue Hintergrundprozesse startet.
Jeder dieser drei Prozesse soll unmittelbar hintereinander 200-mal die Meldung „Hallo, hier ist Prozess x“ ausgeben, wobei x je nach Prozess „A“ „B“ oder „C“ ist. Auch hier lassen sich gut Shellscripts einsetzen.

Was beobachten Sie bezüglich der Reihenfolge der Prozessausführung?
Dokumentieren Sie die UNIX-Kommandos, mit denen Sie die Aufgaben gelöst haben.

**Shell-Script:**
```sh
#!/bin/bash
if [ $# -ne 2 ]; then
  echo "Please specify exactly two arguments: processId, sleepTime"
  exit 1
fi

sleep $2
echo "Hier Prozess $1"
sleep $2
echo "Hier Prozess $1"
```

**Programm Status**:
```sh
$ ps
```

**Prozess vorzeitig beenden:**
```sh
$ ./prozess.sh 1 10 &
[2] 118233

$ kill 118233
[2]-  Terminated              ./prozess.sh 1 30
```