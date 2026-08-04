	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb0
	ldr r0, [r5]
	ldrb r1, [r0, #4]
	ldr r3, _0811F304 @ =gCurLevelInfo
	adds r0, r4, #0
	adds r0, #0x56
	ldrb r2, [r0]
	movs r0, #0xcd
	lsls r0, r0, #3
	muls r0, r2, r0
	adds r0, r0, r3
	ldr r2, _0811F308 @ =0x0000065E
	adds r0, r0, r2
	ldrb r2, [r0]
	movs r0, #0
	bl sub_08002888
	adds r3, r0, #0
	ldrb r0, [r3]
	cmp r0, #0
	bne _0811F2AE
	ldrb r0, [r3, #1]
	cmp r0, #0
	bne _0811F2AE
	ldrb r0, [r3, #2]
	cmp r0, #0
	beq _0811F348
_0811F2AE:
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r6, [r3]
	mov r8, r6
	adds r5, r2, #0
	ldrb r7, [r2]
	cmp r6, r7
	bne _0811F2D6
	ldrb r0, [r3, #1]
	ldrb r1, [r2, #1]
	cmp r0, r1
	bne _0811F2D6
	ldrb r0, [r3, #2]
	ldrb r1, [r2, #2]
	eors r0, r1
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r7, r1, #0x1f
	cmp r7, #0
	beq _0811F310
_0811F2D6:
	movs r1, #0
	mov r2, r8
	strb r2, [r5]
	ldrb r0, [r3, #1]
	strb r0, [r5, #1]
	ldrb r0, [r3, #2]
	strb r0, [r5, #2]
	strb r1, [r5, #3]
	adds r0, r4, #0
	adds r0, #0xb0
	ldr r0, [r0]
	ldrh r0, [r0, #0x14]
	adds r1, r4, #0
	adds r1, #0xc6
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0xc4
	ldrh r1, [r2]
	ldr r0, _0811F30C @ =0x0000FDFF
	ands r0, r1
	strh r0, [r2]
	b _0811F402
	.align 2, 0
_0811F304: .4byte gCurLevelInfo
_0811F308: .4byte 0x0000065E
_0811F30C: .4byte 0x0000FDFF
_0811F310:
	adds r5, r4, #0
	adds r5, #0xc4
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0811F402
	strb r6, [r2]
	ldrb r0, [r3, #1]
	strb r0, [r2, #1]
	ldrb r0, [r3, #2]
	strb r0, [r2, #2]
	strb r7, [r2, #3]
	adds r0, r4, #0
	adds r0, #0xb0
	ldr r0, [r0]
	ldrh r1, [r0, #0x14]
	adds r0, r4, #0
	adds r0, #0xc6
	strh r1, [r0]
	ldrh r1, [r5]
	ldr r0, _0811F344 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r5]
	b _0811F402
	.align 2, 0
_0811F344: .4byte 0x0000FDFF
_0811F348:
	adds r2, r4, #0
	adds r2, #0xc4
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	bne _0811F402
	ldr r0, [r5]
	ldrh r5, [r0, #8]
	mov sb, r5
	adds r1, r4, #0
	adds r1, #0xb8
	subs r2, #0xa
	ldrh r5, [r2]
	movs r7, #6
	ldrsh r3, [r0, r7]
	movs r7, #0
	ldrsh r0, [r1, r7]
	movs r7, #0
	mov ip, r7
	mov r8, r1
	cmp r3, r0
	bne _0811F382
	cmp sb, r5
	bne _0811F382
	movs r0, #1
	mov ip, r0
_0811F382:
	mov r1, ip
	cmp r1, #0
	beq _0811F3A4
	ldrh r1, [r6]
	ldr r0, _0811F3A0 @ =0x0000FDFF
	ands r0, r1
	movs r1, #0
	strh r0, [r6]
	adds r0, r4, #0
	adds r0, #0xb4
	strb r1, [r0]
	strb r1, [r0, #1]
	strb r1, [r0, #2]
	strb r1, [r0, #3]
	b _0811F402
	.align 2, 0
_0811F3A0: .4byte 0x0000FDFF
_0811F3A4:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0811F402
	adds r3, r4, #0
	adds r3, #0xc6
	ldrh r1, [r3]
	movs r5, #0
	ldrsh r0, [r3, r5]
	cmp r0, #0
	blt _0811F3C6
	subs r0, r1, #1
	strh r0, [r3]
	b _0811F402
_0811F3C6:
	mov r7, r8
	ldrh r1, [r7]
	adds r0, r4, #0
	adds r0, #0xbc
	strh r1, [r0]
	ldrh r0, [r2]
	adds r1, r4, #0
	adds r1, #0xbe
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0xb0
	ldr r0, [r2]
	ldrh r1, [r0, #6]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r1, [r0]
	ldr r0, [r2]
	ldrh r1, [r0, #8]
	adds r0, r4, #0
	adds r0, #0xc2
	strh r1, [r0]
	ldr r0, [r2]
	ldrh r0, [r0, #0x14]
	strh r0, [r3]
	ldrh r1, [r6]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r6]
_0811F402:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	.syntax divided
