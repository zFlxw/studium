Eine IP-Adresse dient zur eindeutigen Adressierung eines Geräts im Internet. Somit wird die Erreichbarkeit und der Datenaustausch ermöglicht.

## Arten von IP-Adressen
- IPv4: 32 Bit Adressraum ($2^{32} = 4,294,967,296$), dargestellt in vier Oktetten in dezimaler Schreibweise
	- Beispiel: `161.25.166.24`
- IPv6: 128 Bit Adressraum ($2^{128}=3,4\cdot10^{38}$), dargestellt in hexadezimaler Schreibweise
	- Beispiel: `2001:0fab:215f:1115:0501:4142:551f:aaf25`

## Spezielle Adressräume
Folgende IPv4-Adressräume haben spezielle Eigenschaften.

**Private Adressräume**
- 10.0.0.0/8
- 100.64.0.0 - 100.127.255.255 (Carrier-grade NAT)
- 172.16.0.0/12
- 192.168.0.0/16

**Lokaler Adressraum**
- 127.0.0.0 - 127.255.255.255
- `localhost` ist definiert als 127.0.0.1 (oder ::1)

**Broadcast**
- 255.255.255.255

## Adresszuordnung
IP-Adressen können fest zugeordnet (statisch) sein oder dynamisch vergeben werden. Eine statische IP-Adressvergabe erfolgt meist nur bei Servern, während normale Clients meist eine dynamische IP-Adresse erhalten.

Die dynamische Vergabe erfolgt über [[DHCP]].