/* -*- mode:c -*-
 *
 * Copyright 2017 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* Declare symbolic names for all the GPIOs that we care about.
 * Note: Those with interrupt handlers must be declared first. */

/*
 * ADCs are not configured in this file but listed below for reference.
 *
 * PIN(4, 4) ADC1: IADP_AMON_BMON
 * PIN(4, 3) ADC2: PPVAR_BOOSTIN_SENSE
 */

GPIO_INT(USB_C0_PD_INT_ODL,	PIN(3, 7), GPIO_INT_FALLING,		tcpc_alert_event)
GPIO_INT(USB_C1_PD_INT_ODL,	PIN(7, 1), GPIO_INT_FALLING,		tcpc_alert_event)
#ifdef CONFIG_POWER_S0IX
GPIO_INT(PCH_SLP_S0_L,		PIN(7, 5), GPIO_INT_BOTH,		power_signal_interrupt)
#endif
GPIO_INT(PCH_SLP_SUS_L,		PIN(6, 2), GPIO_INT_BOTH,		power_signal_interrupt)
GPIO_INT(RSMRST_L_PGOOD,	PIN(B, 0), GPIO_INT_BOTH,		power_signal_interrupt)
GPIO_INT(PMIC_DPWROK,		PIN(C, 7), GPIO_INT_BOTH,		power_signal_interrupt)
GPIO_INT(POWER_BUTTON_L,	PIN(0, 3), GPIO_INT_BOTH | GPIO_PULL_UP,power_button_interrupt)
GPIO_INT(LID_OPEN,		PIN(8, 3), GPIO_INT_BOTH,		lid_interrupt)
GPIO_INT(VOLUME_DOWN_L,		PIN(7, 3), GPIO_INT_BOTH | GPIO_PULL_UP,button_interrupt)
GPIO_INT(VOLUME_UP_L,		PIN(8, 6), GPIO_INT_BOTH | GPIO_PULL_UP,button_interrupt)
GPIO_INT(WP_L,			PIN(9, 3), GPIO_INT_BOTH,		switch_interrupt)
GPIO_INT(AC_PRESENT,		PIN(C, 1), GPIO_INT_BOTH,		extpower_interrupt)
GPIO_INT(USB_C0_VBUS_WAKE_L,	PIN(9, 7), GPIO_INT_BOTH | GPIO_PULL_UP,vbus0_evt)
GPIO_INT(USB_C1_VBUS_WAKE_L,	PIN(C, 5), GPIO_INT_BOTH | GPIO_PULL_UP,vbus1_evt)
GPIO_INT(USB_C0_BC12_INT_L,	PIN(D, 2), GPIO_INT_FALLING,		usb0_evt)
GPIO_INT(USB_C1_BC12_INT_L,	PIN(D, 3), GPIO_INT_FALLING,		usb1_evt)
GPIO_INT(ACCELGYRO3_INT_L,	PIN(3, 6), GPIO_INT_FALLING | GPIO_SEL_1P8V,	bmi160_interrupt)
GPIO_INT(TABLET_MODE_L,		PIN(7, 2), GPIO_INT_BOTH,		tablet_mode_isr)
/* Used to wake up system from deep S3. */
/* GPIO_INT(TP_INT_CONN,		PIN(4, 2), GPIO_INT_BOTH, trackpad_connect) dnojiri: Revisit */
/* GPIO_INT(ALS_INT,		PIN(3, 2),,) dnojiri: Revisit */
/* GPIO_INT(3AXIS_INT,		PIN(9, 5),,) dnojiri: Revisit */

GPIO(ENABLE_BACKLIGHT_L,		PIN(6, 7), GPIO_OUT_LOW)	/* LCD backlight */
GPIO(PP3300_DX_WLAN,		PIN(B, 1), GPIO_OUT_LOW)	/* Enable WLAN 3.3V Power */
GPIO(CPU_PROCHOT,		PIN(8, 1), GPIO_OUT_HIGH)	/* PROCHOT# to SOC */
GPIO(PCH_ACPRESENT,		PIN(5, 0), GPIO_ODR_LOW)	/* ACOK to SOC */
GPIO(PCH_WAKE_L,		PIN(A, 3), GPIO_ODR_HIGH)	/* Wake SOC */
GPIO(PCH_RSMRST_L,		PIN(7, 0), GPIO_OUT_LOW)	/* RSMRST# to SOC */
GPIO(PCH_PWRBTN_L,		PIN(7, 4), GPIO_ODR_HIGH)	/* Power Button to SOC */
GPIO(EC_PLATFORM_RST,		PIN(4, 5), GPIO_OUT_LOW)	/* EC Reset to LDO_EN */
GPIO(SYS_RESET_L,		PIN(6, 1), GPIO_ODR_HIGH)	/* Cold Reset to SOC */
GPIO(PMIC_SLP_SUS_L,		PIN(8, 5), GPIO_OUT_LOW)	/* SLP_SUS# to PMIC */
GPIO(BATTERY_PRESENT_L,		PIN(3, 4), GPIO_INPUT)		/* Battery Present */
GPIO(CCD_MODE_ODL,		PIN(6, 3), GPIO_INPUT)		/* Case Closed Debug Mode */
GPIO(ENTERING_RW,		PIN(7, 6), GPIO_OUTPUT)		/* EC Entering RW */
GPIO(PMIC_INT_L,		PIN(6, 0), GPIO_INPUT)		/* PMIC interrupt */
#ifndef CONFIG_POWER_S0IX
GPIO(PCH_SLP_S0_L,		PIN(7, 5), GPIO_INPUT)
#endif
GPIO(CR50_RESET_ODL,		PIN(0, 2), GPIO_ODR_HIGH)	/* Cr50 Reset. dnojiri: unused. */
GPIO(GPP_B14,			PIN(C, 2), GPIO_INPUT) /* Used for Intel's experimental uCode/P-unit update */
/* Will be used to shut down EC on board_hibernate. */
GPIO(EC_HIBERNATE,		PIN(0, 1), GPIO_OUT_LOW)
/* GPIO(PCH_RTCRST,		PIN(E, 7), GPIO_INPUT) dnojiri: Revisit */

/* I2C pins - these will be reconfigured for alternate function below */
GPIO(I2C0_0_SCL,		PIN(B, 5), GPIO_INPUT)		/* EC_I2C0_0_USBC_3V3_SCL */
GPIO(I2C0_0_SDA,		PIN(B, 4), GPIO_INPUT)		/* EC_I2C0_0_USBC_3V3_SDA */
GPIO(I2C0_1_SCL,		PIN(B, 3), GPIO_INPUT)		/* EC_I2C0_1_USBC_3V3_SCL */
GPIO(I2C0_1_SDA,		PIN(B, 2), GPIO_INPUT)		/* EC_I2C0_1_USBC_3V3_SDA */
GPIO(I2C1_SCL,			PIN(9, 0), GPIO_INPUT)		/* EC_I2C1_3V3_SCL */
GPIO(I2C1_SDA,			PIN(8, 7), GPIO_INPUT)		/* EC_I2C1_3V3_SDA */
GPIO(I2C2_SCL,			PIN(9, 2), GPIO_INPUT)		/* EC_I2C2_PMIC_3V3_SCL */
GPIO(I2C2_SDA,			PIN(9, 1), GPIO_INPUT)		/* EC_I2C2_PMIC_3V3_SDA */
GPIO(I2C3_SCL,			PIN(D, 1), GPIO_INPUT | GPIO_SEL_1P8V)	/* EC_I2C3_SENSOR_1V8_SCL */
GPIO(I2C3_SDA,			PIN(D, 0), GPIO_INPUT | GPIO_SEL_1P8V)	/* EC_I2C3_SENSOR_1V8_SDA */

/* rev0: 5V enables: INPUT=1.5A, OUT_LOW=OFF, OUT_HIGH=3A */
GPIO(USB_C0_5V_EN,		PIN(4, 0), GPIO_OUT_LOW)	/* C0 5V Enable */
GPIO(USB_C0_3A_EN,		PIN(3, 5), GPIO_OUT_LOW)	/* C0 Enable 3A */
GPIO(USB_C0_CHARGE_L,		PIN(C, 0), GPIO_OUT_LOW)	/* C0 Charge enable. Active low. */
GPIO(USB_C1_5V_EN,		PIN(3, 3), GPIO_OUT_LOW)	/* C1 5V Enable */
GPIO(USB_C1_3A_EN,		PIN(6, 6), GPIO_OUT_LOW)	/* C1 3A Enable */
GPIO(USB_C1_CHARGE_L,		PIN(C, 3), GPIO_OUT_LOW)	/* C1 Charge enable. Active low. */
GPIO(USB_C0_PD_RST_L,		PIN(C, 6), GPIO_ODR_HIGH)	/* C0 PD Reset */
GPIO(USB_C1_PD_RST,		PIN(0, 0), GPIO_OUT_LOW)	/* C1 PD Reset */
GPIO(USB_C0_DP_HPD,		PIN(9, 4), GPIO_INPUT)		/* C0 DP Hotplug Detect */
GPIO(USB_C1_DP_HPD,		PIN(A, 5), GPIO_INPUT)		/* C1 DP Hotplug Detect */
GPIO(USB_PP3300_USB_PD,		PIN(8, 4), GPIO_INPUT)		/* Reserved. Currently, has no effect. */
GPIO(USB2_OTG_ID,		PIN(5, 7), GPIO_ODR_LOW)	/* OTG ID */

/* Sensors */

/* Trackpad */
GPIO(TP_INT_EN,			PIN(A, 1), GPIO_OUT_LOW)

/* LED */
GPIO(LED1,			PIN(A, 7), GPIO_OUT_LOW)

/* Alternate functions GPIO definitions */
ALTERNATE(PIN_MASK(6, 0x30), 1, MODULE_UART, 0)	/* GPIO64-65 UART from EC to Servo */
ALTERNATE(PIN_MASK(8, 0x80), 1, MODULE_I2C, 0)	/* GPIO87 EC_I2C1_3V3_SDA */
ALTERNATE(PIN_MASK(9, 0x01), 1, MODULE_I2C, 0)	/* GPIO90 EC_I2C1_3V3_SCL */
ALTERNATE(PIN_MASK(9, 0x06), 1, MODULE_I2C, 0)	/* GPIO91-92 EC_I2C2_SDA/SCL */
ALTERNATE(PIN_MASK(B, 0x30), 1, MODULE_I2C, 0)	/* GPIOB4-B5 EC_I2C0_0_SDA/SCL */
ALTERNATE(PIN_MASK(B, 0x0C), 1, MODULE_I2C, 0)	/* GPOPB2-B3 EC_I2C0_1_SDA/SCL */
ALTERNATE(PIN_MASK(D, 0x03), 1, MODULE_I2C, 0)	/* GPIOD0-D1 EC_I2C3_SDA/SCL */
ALTERNATE(PIN_MASK(B, 0x40), 1, MODULE_PWM, 0)	/* GPIOB6 PWM1 Fan control */
ALTERNATE(PIN_MASK(8, 0x01), 1, MODULE_PWM, 0)	/* GPIO80 PWM3 LED White */
ALTERNATE(PIN_MASK(B, 0x80), 1, MODULE_PWM, 0)	/* GPIOB7 PWM5 LED Yellow */
ALTERNATE(PIN_MASK(A, 0x40), 1, MODULE_PWM, 0)	/* GPIOA6 TA2 */
ALTERNATE(PIN_MASK(C, 0x10), 1, MODULE_PWM, 0)	/* GPIOC4 PWM2 */

/* Keyboard pins */
#define GPIO_KB_INPUT (GPIO_INPUT | GPIO_PULL_UP)
#define GPIO_KB_OUTPUT (GPIO_ODR_HIGH)
ALTERNATE(PIN_MASK(3, 0x03), 0, MODULE_KEYBOARD_SCAN, GPIO_KB_INPUT)
ALTERNATE(PIN_MASK(2, 0xfc), 0, MODULE_KEYBOARD_SCAN, GPIO_KB_INPUT)
ALTERNATE(PIN_MASK(2, 0x03), 0, MODULE_KEYBOARD_SCAN, GPIO_KB_OUTPUT)
ALTERNATE(PIN_MASK(1, 0x7f), 0, MODULE_KEYBOARD_SCAN, GPIO_KB_OUTPUT)
ALTERNATE(PIN_MASK(0, 0xf0), 0, MODULE_KEYBOARD_SCAN, GPIO_KB_OUTPUT)
ALTERNATE(PIN_MASK(8, 0x04), 0, MODULE_KEYBOARD_SCAN, GPIO_KB_OUTPUT)
GPIO(KBD_KSO2,			PIN(1, 7), GPIO_OUT_LOW)