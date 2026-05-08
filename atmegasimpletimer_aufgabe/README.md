# **Arbeitsauftrag: Timer0-Experimente mit dem ATmega-Mikrocontroller**

---

## **1. Grundlegendes Ausprobieren**

**Aufgabe:**  
Lade den gegebenen Code auf deinen Mikrocontroller und beobachte das Verhalten der LED an **PD7**.

- Was passiert? Blinkt die LED?
- Warum blinkt sie (oder warum nicht)?
- Notiere deine Beobachtungen und erklären Sie, warum die LED in dieser Konfiguration blinkt oder nicht.

---

**Abgabe 1:**  
Halte deine Beobachtungen und eine kurze Erklärung (max. 5 Sätze) in einer Textdatei fest. Gib diese ab.

---

---

## **2. Experimentieren mit dem Prescaler**

**Aufgabe:**  
Ändere den **Prescaler** im Code, indem du die Zeilen für `TCCR0B` anpasst. Probiere alle möglichen Prescaler-Werte aus:

- **Kein Prescaler** (`CS00`)
- **Prescaler 8** (`CS01`)
- **Prescaler 64** (`CS00 | CS01`)
- **Prescaler 256** (`CS02`)
- **Prescaler 1024** (`CS00 | CS02`)

Beobachte, wie sich das Blinkverhalten der LED ändert.

- Wie wirkt sich der Prescaler auf die Blinkfrequenz aus?
- Warum ist das so?

---

**Abgabe 2:**  
Erstelle eine Tabelle mit den Prescaler-Werten und der gemessenen/beobachteten Blinkfrequenz (z. B. "sehr schnell", "langsam", etc.). Gib diese Tabelle ab.

---

---

## **3. Experimentieren mit dem Vergleichsregister (OCR0A)**

**Aufgabe:**  
Ändere den Wert von `**OCR0A**` im Code. Beginne mit kleinen Werten (z. B. 10, 50, 100) und steigere ihn bis nahe an den Maximalwert (255).

- Wie wirkt sich `OCR0A` auf das Blinkverhalten aus?
- Warum löst der Timer-Interrupt bei bestimmten Werten schneller oder langsamer aus?

---

**Abgabe 3:**  
Notiere 3 verschiedene `OCR0A`-Werte und beschreibe, wie sich die Blinkfrequenz der LED jeweils ändert. Gib diese Notizen ab.

---

---

## **4. Praktische Anwendung: Blinkzeiten einstellen**

**Aufgabe:**  
Stelle den Code so ein, dass die LED an **PD7** mit den folgenden Blinkzeiten blinkt. Nutze dafür eine Kombination aus **Prescaler** und `**OCR0A**`.

1. **Blinkzeit: 0,5 Sekunden** (LED an für 0,5 s, aus für 0,5 s)
2. **Blinkzeit: 1 Sekunde** (LED an für 1 s, aus für 1 s)
3. **Blinkzeit: 2 Sekunden** (LED an für 2 s, aus für 2 s)

**Hinweis:**

- Die tatsächliche Blinkzeit hängt von der Taktfrequenz (`F_CPU = 16 MHz`) und der gewählten Prescaler-`OCR0A`-Kombination ab.
- Nutze die Formel für die Berechnung der Interrupt-Frequenz:  
**Interrupt-Frequenz = F_CPU / (Prescaler × (OCR0A + 1))**
- Die Blinkzeit ist doppelt so lang wie die Zeit zwischen zwei Interrupts (weil die LED im ISR umgeschaltet wird).

---

**Abgabe 4:**  
Gib deinen angepassten Code für die drei Blinkzeiten ab. Kommentiere im Code, welche Prescaler- und `OCR0A`-Werte du gewählt hast und warum.

---

---

## **Zusatzfrage (optional)**

- Warum wird im ISR ein Zähler (`count_overlow`) verwendet? Was würde passieren, wenn man diesen weglassen würde?
- Wie könnte man den Code so anpassen, dass die LED **PD6** statt **PD7** blinkt?

---

**Viel Erfolg!** 🚀
