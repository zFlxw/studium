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

## Aufgabe 3.3
Implementierung des Prozessor-Datenmodells in Java. Code in separatem Java-Projekt.

## Aufgabe 3.4
Schreiben Sie unter C ein Programm, das die Funktion `fork` verwendet, um ein Kindprozess zu erzeugen. Vater und Kind sollen jeweils in einer Schleife mit 500 Durchläufen jeweils den Schleifenzähler ausgeben. Lassen Sie das Programm mehrmals laufen und vergleichen Sie die Ausgaben! Erklären Sie das Verhalten des Programms.

Code:
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  printf("Start of process with ID: ");
  int pid1, pid2;
  pid1 = getpid();
  pid2 = fork();
  if (pid2 < 0) {
    perror("\n Fork war nicht erfolgreich");
    exit(1);
  }

  printf("%d\n", pid1);
  for (int i = 0; i < 500; i++) {
    printf("%d\n", i);
  }

  return EXIT_SUCCESS;
}
```

**Verhalten des Programms:**
Das Programm gibt zunächst die Zahlen 1 bis ~200 aus und fängt dann bereits mit der Ausgabe der Zahlen des Kindprozesses an. Das liegt daran, dass der Kindprozess parallel in einem separaten Thread gestartet wird, sodass beide Prozesse „parallel“ laufen (und dadurch die jeweiligen Durchläufe abwechseln ausgegeben werden).

## Aufgabe 3.5
Ebenfalls Implementierung in dediziertem Java-Projekt.

## Aufgabe 3.6
Erstellen Sie eine Thread-Klasse Race, die in der run()-Methode 10-mal eine Schleife
durchläuft, in der zuerst den Wert j gesetzt wird und anschließend die Operation k=k+j
durchführt wird.
```java
package threads;

public class Race implements Runnable {
    private int value;
    private boolean useYield;

    public Race(int value, boolean useYield) {
        this.value = value;
        this.useYield = useYield;
    }

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            ThreadContainer.j = value;
            if (useYield) {
                Thread.yield();
            }

            ThreadContainer.k = ThreadContainer.k + ThreadContainer.j;
            if (useYield) {
                Thread.yield();
            }
        }
    }
}
```

Erstellen Sie eine Klasse, die als Container für zwei globale Variablen j und k dient (static).
Initialisieren Sie die Werte `j=0, k=5`. Erzeugen Sie in der Main-Methode zwei Threads, die den Wert j auf 1 bzw. auf -1 setzen.
```java
package threads;

public class ThreadContainer {
    public static int j = 0;
    public static int k = 5;

    static void main() throws InterruptedException {
        Thread t1 = new Thread(new Race(1, false));
        Thread t2 = new Thread(new Race(-1, false));

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.printf("yield=%s -> k=%d, j=%d%n", false, k, j);
    }
}
```

Beschreiben Sie das Ergebnis.
> Es fällt auf, dass `k`meist den Wert `5`hat. Das hat den Grund, dass die Threads sich „gegenseitig aushebeln“, wodurch `j`bei 10 Durchläufen durchschnittlich 5x den Wert `-1`und 5x den Wert `1`hat.

Erleichtern Sie nach jeder Operation innerhalb der Schleife einen Thread-Wechsel durch
Verwendung von Thread.yield(). Wie ändert sich das Ergebnis?
> Durch die Verwendung von `Thread.yield()` ist die Varianz der Ergebnisse deutlich erhöht und es tritt weniger oft der Fall ein, in dem `k=5` gilt.