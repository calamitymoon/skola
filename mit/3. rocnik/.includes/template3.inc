.MACRO seg_led_pwr_on 
	sbi DispCtrlP, 4
.ENDMACRO

.MACRO seg_led_pwr_off
	cbi DispCtrlP, 4
.ENDMACRO


