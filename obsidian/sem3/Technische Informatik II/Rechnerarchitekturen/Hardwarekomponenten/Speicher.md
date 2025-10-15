Als Speicher bezeichnet man Hardware, die eingesetzt wird um Daten zu persistieren (dauerhaft zu speichern). Dabei gibt es verschiedene Arten von Speicher, die je nach Anwendungszweck eingesetzt werden.

![[Pasted image 20251015203205.png]]
Die Grafik zeigt eine Auflistung, welche Speicherkomponenten ein Computer überlicherweise verwenden kann. Dabei sieht man, dass der Speicher, auf den der [[Prozessor]] am schnellsten zugreifen kann, sehr klein ist. Darüber hinaus wird zwischen zwei Arten von Speichern unterschieden:
- **transienter Speicher**: Daten gehen beim Ausschalten verloren
- **persistenter Speicher**: Daten werden langfristig gespeichert

## Arten von Speicher
Typisch sind folgende Speicherhardware:
- **Register**: Befinden sich im Prozessor; super kleiner Speicher, aber schnellstmögliche Zugriffszeit
- **Cache**: Unterteilt in L1-L3 Cache (L1 und L2 Cache befinden sich in jedem Kern, L3 Cache innerhalb der gesamten CPU)
- **RAM** (Random Access Memory; Arbeitsspeicher): Schnellstmöglicher „externer“ transiente Speicher
- **Festplatten**: Langsam, aber große Speicherkapazität und geeignet als persistener Speicher
- **Magnetbänder**: Sehr größer Speicher, allerdings auch sehr langsam. Wird eigentlich nur noch im Server-Bereich verwendet, bspw. für Backups