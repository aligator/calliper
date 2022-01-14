# calliper
Read Vogel digital calliper Mini-USB with an arduino. (Maybe others work also. If not, create an issue, maybe it can be adapted.)

# Prequesites
- A Vogel calliper with a Mini-USB (e.g. [Amazon](https://www.amazon.de/gp/product/B000VD753Q/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1))
- An arduino with **3.3V** logic. I used a NodeMCU v3 ESP-8266.  
Alternatively you may use a step up module to convert the 3.3V logic up to 5V. (Not tested...)
- A USB-mini cable.

# Connection
(Example for a NodeMCU v3)  
Color code is based on the default USB color code (black, red, white, green)
```
- D5 -> CLOCK  -> White
- D6 -> DATA   -> Green
- G  -> Ground -> Black
```

# Troubleshooting
- No output or random mm-values to the Serial connection:  
You may have switched CLOCK and DATA
