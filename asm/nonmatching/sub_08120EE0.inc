	.syntax unified
	.text

	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xb0
	ldr r0, [r4]
	ldrb r1, [r0, #4]
	ldr r3, _08120F38 @ =gCurLevelInfo
	adds r0, r5, #0
	adds r0, #0x56
	ldrb r2, [r0]
	movs r0, #0xcd
	lsls r0, r0, #3
	muls r0, r2, r0
	adds r0, r0, r3
	ldr r2, _08120F3C @ =0x0000065E
	adds r0, r0, r2
	ldrb r2, [r0]
	movs r0, #0
	bl sub_08002888
	adds r3, r0, #0
	adds r0, r5, #0
	adds r0, #0xb6
	ldrh r0, [r0]
	movs r6, #1
	ands r6, r0
	cmp r6, #0
	beq _08120F5A
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	cmp r1, #0
	beq _08120F40
	ldr r0, [r4]
	ldrh r0, [r0, #0x14]
	lsrs r0, r0, #8
	movs r1, #0
	strb r0, [r3]
	ldr r0, [r4]
	ldrh r0, [r0, #0x14]
	strb r0, [r3, #1]
	ldr r0, [r4]
	ldrh r0, [r0, #0x12]
	b _08120F52
	.align 2, 0
_08120F38: .4byte gCurLevelInfo
_08120F3C: .4byte 0x0000065E
_08120F40:
	ldr r0, [r4]
	ldrh r0, [r0, #0x18]
	lsrs r0, r0, #8
	strb r0, [r3]
	ldr r0, [r4]
	ldrh r0, [r0, #0x18]
	strb r0, [r3, #1]
	ldr r0, [r4]
	ldrh r0, [r0, #0x16]
_08120F52:
	lsrs r0, r0, #8
	strb r0, [r3, #2]
	strb r1, [r3, #3]
	b _08120F8A
_08120F5A:
	ldr r1, [r4]
	ldrh r0, [r1, #0x14]
	lsrs r2, r0, #8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldrh r0, [r1, #0x12]
	lsrs r1, r0, #8
	ldrb r0, [r3]
	cmp r0, r2
	bne _08120F8A
	ldrb r0, [r3, #1]
	cmp r0, r4
	bne _08120F8A
	ldrb r0, [r3, #2]
	movs r2, #1
	cmp r0, r1
	beq _08120F7E
	movs r2, #0
_08120F7E:
	cmp r2, #0
	beq _08120F8A
	strb r6, [r3]
	strb r6, [r3, #1]
	strb r6, [r3, #2]
	strb r6, [r3, #3]
_08120F8A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	.syntax divided
