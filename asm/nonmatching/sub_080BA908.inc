	.syntax unified
	.text

	push {r4, lr}
	mov ip, r0
	adds r0, #0x85
	ldrb r0, [r0]
	movs r1, #0xc0
	ands r1, r0
	cmp r1, #0x80
	beq _080BA91C
	cmp r1, #0xc0
	bne _080BA948
_080BA91C:
	mov r0, ip
	adds r0, #0x3c
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #8
	mov r2, ip
	ldr r0, [r2, #0x40]
	adds r4, r0, r1
	ldr r3, [r2, #0x44]
	ldr r0, _080BA940 @ =0xFFFFF000
	ands r4, r0
	ldr r0, _080BA944 @ =0x00000FFF
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r4, r0
	subs r0, r0, r1
	str r0, [r2, #0x40]
	b _080BA970
	.align 2, 0
_080BA940: .4byte 0xFFFFF000
_080BA944: .4byte 0x00000FFF
_080BA948:
	mov r0, ip
	ldr r4, [r0, #0x40]
	adds r0, #0x3f
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #8
	mov r1, ip
	ldr r0, [r1, #0x44]
	adds r3, r0, r2
	ldr r0, _080BA978 @ =0xFFFFF0FF
	ands r3, r0
	movs r1, #0xf0
	lsls r1, r1, #4
	ands r4, r1
	asrs r0, r4, #1
	ands r0, r1
	adds r0, r3, r0
	subs r0, r0, r2
	mov r2, ip
	str r0, [r2, #0x44]
_080BA970:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BA978: .4byte 0xFFFFF0FF

	.syntax divided
