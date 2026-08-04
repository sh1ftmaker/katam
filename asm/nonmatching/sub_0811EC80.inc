	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	mov sb, r6
	adds r1, r6, #0
	adds r1, #0x56
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _0811ECB4
	ldr r2, _0811ECAC @ =gCurLevelInfo
	adds r1, r0, #0
	movs r0, #0xcd
	lsls r0, r0, #3
	muls r0, r1, r0
	adds r0, r0, r2
	ldr r1, _0811ECB0 @ =0x0000065E
	adds r0, r0, r1
	ldrb r0, [r0]
	b _0811ECB6
	.align 2, 0
_0811ECAC: .4byte gCurLevelInfo
_0811ECB0: .4byte 0x0000065E
_0811ECB4:
	movs r0, #0xff
_0811ECB6:
	cmp r0, #0xff
	beq _0811ECDE
	lsls r3, r0, #3
	ldr r1, _0811ED70 @ =gUnk_02022F40
	adds r1, r0, r1
	ldrb r0, [r1]
	adds r2, r0, #1
	strb r2, [r1]
	adds r0, r0, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0811ED74 @ =gUnk_02022EC0
	lsls r1, r0, #2
	adds r1, r1, r2
	str r6, [r1]
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #0
	str r1, [r0]
_0811ECDE:
	mov r5, sb
	adds r5, #0xe0
	movs r2, #0
	mov r8, r2
	mov r4, r8
	strb r4, [r5]
	mov r4, sb
	adds r4, #0xe3
	ldrb r1, [r4]
	movs r0, #0xcf
	ands r0, r1
	strb r0, [r4]
	mov r0, sb
	movs r1, #0
	bl sub_0811EA60
	mov r0, sb
	movs r1, #1
	bl sub_0811EA60
	mov r0, sb
	movs r1, #2
	bl sub_0811EA60
	mov r0, sb
	movs r1, #3
	bl sub_0811EA60
	adds r2, r6, #0
	adds r2, #0x62
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	adds r3, r5, #0
	adds r7, r4, #0
	cmp r0, #0
	beq _0811ED30
	ldrb r0, [r7]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r7]
_0811ED30:
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0811ED42
	ldrb r0, [r7]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r7]
_0811ED42:
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge _0811ED4C
	rsbs r0, r0, #0
_0811ED4C:
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r6, #0
	adds r0, #0x50
	ldrh r2, [r0]
	movs r4, #0
	ldrsh r1, [r0, r4]
	adds r4, r0, #0
	cmp r1, #0
	bge _0811ED78
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r2, r1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0811ED88
	b _0811ED84
	.align 2, 0
_0811ED70: .4byte gUnk_02022F40
_0811ED74: .4byte gUnk_02022EC0
_0811ED78:
	ldr r1, _0811EE14 @ =0xFFFFFE00
	adds r0, r2, r1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0811ED88
_0811ED84:
	mov r2, r8
	strh r2, [r4]
_0811ED88:
	lsls r0, r5, #0x18
	asrs r5, r0, #0x18
	cmp r5, #0
	beq _0811ED92
	b _0811EF1C
_0811ED92:
	adds r0, r6, #0
	bl sub_08070504
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811EDA0
	b _0811EEE6
_0811EDA0:
	ldrb r0, [r7]
	movs r2, #0xf7
	ands r2, r0
	strb r2, [r7]
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	bne _0811EDB8
	movs r1, #8
	adds r0, r2, #0
	orrs r0, r1
	strb r0, [r7]
_0811EDB8:
	ldrb r1, [r7]
	movs r0, #4
	adds r2, r1, #0
	orrs r2, r0
	movs r0, #0
	orrs r2, r0
	strb r2, [r7]
	adds r0, r6, #0
	adds r0, #0xb0
	ldr r0, [r0]
	ldrh r1, [r0, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0811EE5E
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	bne _0811EDE0
	b _0811EFEA
_0811EDE0:
	movs r0, #0x20
	ands r2, r0
	cmp r2, #0
	beq _0811EDEA
	b _0811EFEA
_0811EDEA:
	ldr r0, [r6, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0811EE18
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r0, #0
	ldrh r1, [r4]
	adds r0, r2, r1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	ldr r0, _0811EE14 @ =0xFFFFFE00
	cmp r1, r0
	blt _0811EE36
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble _0811EE38
	b _0811EE36
	.align 2, 0
_0811EE14: .4byte 0xFFFFFE00
_0811EE18:
	ldr r0, _0811EE4C @ =0xFFFFFE00
	adds r2, r0, #0
	ldrh r1, [r4]
	adds r0, r2, r1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bgt _0811EE36
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bge _0811EE38
_0811EE36:
	strh r0, [r4]
_0811EE38:
	ldrb r1, [r7]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0811EE50
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0xc
	b _0811EE56
	.align 2, 0
_0811EE4C: .4byte 0xFFFFFE00
_0811EE50:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #4
_0811EE56:
	movs r3, #1
	bl sub_08089864
	b _0811EFEA
_0811EE5E:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	bne _0811EE68
	b _0811EFEA
_0811EE68:
	movs r0, #0x10
	ands r2, r0
	cmp r2, #0
	beq _0811EE72
	b _0811EFEA
_0811EE72:
	ldr r0, [r6, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0811EEA0
	ldr r2, _0811EE9C @ =0xFFFFFE00
	adds r1, r2, #0
	ldrh r2, [r4]
	adds r0, r1, r2
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r0, r1
	blt _0811EEBE
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _0811EEC0
	b _0811EEBE
	.align 2, 0
_0811EE9C: .4byte 0xFFFFFE00
_0811EEA0:
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r0, #0
	ldrh r2, [r4]
	adds r0, r1, r2
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r0, r1
	bgt _0811EEBE
	ldr r1, _0811EED4 @ =0xFFFFFE00
	cmp r0, r1
	bge _0811EEC0
_0811EEBE:
	strh r1, [r4]
_0811EEC0:
	ldrb r1, [r7]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0811EED8
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0xc
	b _0811EEDE
	.align 2, 0
_0811EED4: .4byte 0xFFFFFE00
_0811EED8:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #4
_0811EEDE:
	movs r3, #0
	bl sub_08089864
	b _0811EFEA
_0811EEE6:
	ldrh r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bge _0811EF00
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r1, r2
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0811EF0E
	b _0811EF0C
_0811EF00:
	ldr r2, _0811EF18 @ =0xFFFFFE00
	adds r0, r1, r2
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0811EF0E
_0811EF0C:
	strh r5, [r4]
_0811EF0E:
	ldrb r1, [r7]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7]
	b _0811EFEA
	.align 2, 0
_0811EF18: .4byte 0xFFFFFE00
_0811EF1C:
	mov r0, sb
	adds r0, #0xe1
	ldrb r0, [r0]
	cmp r5, r0
	blt _0811EFEA
	ldrb r1, [r7]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _0811EF88
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0811EF62
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0811EFEA
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge _0811EFEA
	ldr r0, [r6, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0811EFB0
	ldrh r0, [r4]
	adds r0, #0x40
_0811EF56:
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x40
	bgt _0811EFC4
	b _0811EFE0
_0811EF62:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0811EFEA
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	ble _0811EFEA
	ldr r0, [r6, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0811EF82
	ldrh r0, [r4]
	adds r0, #0x40
	b _0811EFB4
_0811EF82:
	ldrh r0, [r4]
	subs r0, #0x40
	b _0811EF56
_0811EF88:
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	ble _0811EFA6
	ldr r0, [r6, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0811EFA0
	ldrh r0, [r4]
	adds r0, #0x40
	b _0811EFB4
_0811EFA0:
	ldrh r0, [r4]
	subs r0, #0x40
	b _0811EF56
_0811EFA6:
	ldr r0, [r6, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0811EFCA
_0811EFB0:
	ldrh r0, [r4]
	subs r0, #0x40
_0811EFB4:
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r1, #0x41
	cmp r0, r1
	blt _0811EFE8
	cmp r0, #0x40
	ble _0811EFEA
_0811EFC4:
	movs r0, #0x40
	strh r0, [r4]
	b _0811EFEA
_0811EFCA:
	adds r1, r4, #0
	ldrh r0, [r1]
	adds r0, #0x40
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x40
	ble _0811EFE0
	movs r0, #0x40
	strh r0, [r1]
	b _0811EFEA
_0811EFE0:
	movs r1, #0x40
	rsbs r1, r1, #0
	cmp r0, r1
	bge _0811EFEA
_0811EFE8:
	strh r1, [r4]
_0811EFEA:
	ldr r2, [r6, #8]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0811F028
	mov r4, sb
	adds r4, #0xe2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0811F024
	adds r0, r6, #0
	adds r0, #0xb0
	ldr r0, [r0]
	ldrh r1, [r0, #0x22]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0811F028
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r2, r0
	str r2, [r6, #8]
	ldrb r1, [r7]
	movs r0, #2
	orrs r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r7]
	b _0811F028
_0811F024:
	movs r0, #1
	strb r0, [r4]
_0811F028:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	.syntax divided
