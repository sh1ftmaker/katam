	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	adds r6, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	str r0, [sp]
	adds r5, r7, #0
	adds r5, #0x56
	ldrb r0, [r5]
	mov r8, r0
	adds r4, r7, #0
	adds r4, #0xb0
	ldr r0, [r4]
	ldrb r1, [r0, #4]
	ldr r2, _08120C2C @ =gCurLevelInfo
	mov sl, r2
	movs r3, #0xcd
	lsls r3, r3, #3
	mov sb, r3
	mov r0, r8
	muls r0, r3, r0
	add r0, sl
	ldr r2, _08120C30 @ =0x0000065E
	adds r0, r0, r2
	ldrb r2, [r0]
	movs r0, #0
	bl sub_08002888
	ldr r0, [r0]
	cmp r0, #0
	beq _08120C14
	ldr r0, [r4]
	ldrb r1, [r0, #4]
	ldrb r0, [r5]
	mov r3, sb
	muls r3, r0, r3
	adds r0, r3, #0
	add r0, sl
	ldr r2, _08120C30 @ =0x0000065E
	adds r0, r0, r2
	ldrb r2, [r0]
	movs r0, #0
	bl sub_08002888
	movs r1, #0
	str r1, [r0]
	ldr r0, [r4]
	ldrh r0, [r0, #0x12]
	adds r1, r7, #0
	adds r1, #0xba
	strh r0, [r1]
	adds r2, r7, #0
	adds r2, #0xb8
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08120C14
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r2]
_08120C14:
	adds r2, r6, #0
	adds r2, #0xba
	ldrh r1, [r2]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	ble _08120C34
	subs r0, r1, #1
	strh r0, [r2]
	adds r4, r6, #0
	adds r4, #0xb8
	b _08120C4E
	.align 2, 0
_08120C2C: .4byte gCurLevelInfo
_08120C30: .4byte 0x0000065E
_08120C34:
	adds r1, r6, #0
	adds r1, #0xb8
	ldrh r3, [r1]
	movs r0, #1
	ands r0, r3
	adds r4, r1, #0
	cmp r0, #0
	beq _08120C4A
	movs r0, #0x10
	orrs r0, r3
	strh r0, [r4]
_08120C4A:
	movs r0, #0
	strh r0, [r2]
_08120C4E:
	adds r2, r4, #0
	ldrh r3, [r2]
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	beq _08120CCE
	ldr r1, _08120C98 @ =0x0000FFEF
	ands r1, r3
	strh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08120CA0
	ldr r0, _08120C9C @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2]
	movs r5, #0
	adds r0, r6, #0
	adds r0, #0xb4
	adds r6, r0, #0
	ldrh r0, [r6]
	cmp r5, r0
	bhs _08120CCE
	ldr r4, [sp]
_08120C7E:
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl sub_08001408
	adds r4, #0x18
	adds r5, #1
	ldrh r2, [r6]
	cmp r5, r2
	blo _08120C7E
	b _08120CCE
	.align 2, 0
_08120C98: .4byte 0x0000FFEF
_08120C9C: .4byte 0x0000FFFE
_08120CA0:
	adds r0, r1, #0
	movs r1, #1
	orrs r0, r1
	strh r0, [r4]
	movs r5, #0
	adds r0, r6, #0
	adds r0, #0xb4
	adds r6, r0, #0
	ldrh r3, [r6]
	cmp r5, r3
	bhs _08120CCE
	ldr r4, [sp]
_08120CB8:
	ldr r1, [r4, #0x14]
	mov r0, r8
	movs r2, #0
	movs r3, #0
	bl sub_08001408
	adds r4, #0x18
	adds r5, #1
	ldrh r0, [r6]
	cmp r5, r0
	blo _08120CB8
_08120CCE:
	ldrh r0, [r7, #4]
	adds r0, #1
	strh r0, [r7, #4]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	.syntax divided
