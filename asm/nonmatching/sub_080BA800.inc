	.syntax unified
	.text

	push {r4, r5, lr}
	mov ip, r0
	adds r0, #0x85
	ldrb r0, [r0]
	movs r1, #0xc0
	ands r1, r0
	cmp r1, #0x80
	beq _080BA814
	cmp r1, #0xc0
	bne _080BA844
_080BA814:
	mov r0, ip
	adds r0, #0x3e
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #8
	mov r1, ip
	ldr r0, [r1, #0x40]
	adds r4, r0, r2
	ldr r5, [r1, #0x44]
	ldr r0, _080BA83C @ =0xFFFFF000
	ands r4, r0
	ldr r1, _080BA840 @ =0x00000FFF
	adds r0, r4, r1
	ands r5, r1
	lsls r1, r5, #1
	subs r0, r0, r1
	subs r0, r0, r2
	mov r1, ip
	str r0, [r1, #0x40]
	b _080BA870
	.align 2, 0
_080BA83C: .4byte 0xFFFFF000
_080BA840: .4byte 0x00000FFF
_080BA844:
	mov r0, ip
	ldr r4, [r0, #0x40]
	adds r0, #0x3f
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #8
	mov r1, ip
	ldr r0, [r1, #0x44]
	adds r5, r0, r2
	ldr r0, _080BA878 @ =0xFFFFF0FF
	ands r5, r0
	movs r3, #0xf0
	lsls r3, r3, #4
	ands r4, r3
	asrs r1, r4, #1
	ldr r0, _080BA87C @ =0x000007FF
	subs r0, r0, r1
	ands r0, r3
	adds r0, r5, r0
	subs r0, r0, r2
	mov r1, ip
	str r0, [r1, #0x44]
_080BA870:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BA878: .4byte 0xFFFFF0FF
_080BA87C: .4byte 0x000007FF

	.syntax divided
