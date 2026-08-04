	.syntax unified
	.text

	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldrh r1, [r2, #0x12]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0811F83E
	ldrh r0, [r2, #6]
	lsls r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #0x12
	adds r0, r0, r1
	b _0811F846
_0811F83E:
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r0, r1, r0
_0811F846:
	adds r4, r0, #0
	ldr r2, [r4, #0x10]
	cmp r2, #0
	beq _0811F860
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0811F860
	adds r0, r2, #0
	bl VramFree
_0811F860:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	cmp r0, #0
	beq _0811F86E
	bl EwramFree
_0811F86E:
	adds r0, r4, #0
	adds r0, #0xb0
	ldr r2, [r0]
	adds r6, r0, #0
	adds r5, r4, #0
	adds r5, #0x56
	cmp r2, #0
	beq _0811F8F6
	ldrh r1, [r2, #2]
	movs r0, #0xf8
	lsls r0, r0, #5
	cmp r1, r0
	beq _0811F8BC
	ldrb r0, [r2, #2]
	cmp r0, #0
	bne _0811F894
	ldrb r0, [r5]
	cmp r0, #0xff
	beq _0811F90C
_0811F894:
	ldrb r0, [r2, #2]
	ldrb r1, [r2, #3]
	ldr r4, _0811F8B4 @ =gCurLevelInfo
	ldrb r3, [r5]
	movs r2, #0xcd
	lsls r2, r2, #3
	muls r2, r3, r2
	adds r2, r2, r4
	ldr r3, _0811F8B8 @ =0x0000065E
	adds r2, r2, r3
	ldrb r2, [r2]
	movs r3, #1
	bl sub_08001678
	b _0811F8F6
	.align 2, 0
_0811F8B4: .4byte gCurLevelInfo
_0811F8B8: .4byte 0x0000065E
_0811F8BC:
	ldr r1, _0811F8D0 @ =gUnk_020229E0
	movs r3, #0
	cmp r1, r2
	bne _0811F8D8
	ldr r2, _0811F8D4 @ =gUnk_020229D4
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	b _0811F8F4
	.align 2, 0
_0811F8D0: .4byte gUnk_020229E0
_0811F8D4: .4byte gUnk_020229D4
_0811F8D8:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, #0x24
	cmp r3, #0x1f
	bhi _0811F8F6
	ldr r0, [r6]
	cmp r1, r0
	bne _0811F8D8
	ldr r2, _0811F914 @ =gUnk_020229D4
	movs r1, #1
	lsls r1, r3
	ldr r0, [r2]
	bics r0, r1
_0811F8F4:
	str r0, [r2]
_0811F8F6:
	ldrb r0, [r5]
	cmp r0, #0xff
	beq _0811F90C
	adds r4, r0, #0
	adds r1, r5, #0
	bl sub_08002984
	adds r1, r0, #0
	adds r0, r4, #0
	bl sub_080028CC
_0811F90C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0811F914: .4byte gUnk_020229D4

	.syntax divided
