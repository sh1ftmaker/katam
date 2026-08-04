	.syntax unified
	.text

	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl sub_08120DE0
	cmp r0, #0
	beq _08120E5C
	adds r1, r4, #0
	adds r1, #0xb6
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	movs r4, #0
	orrs r2, r0
	strh r2, [r1]
	movs r0, #1
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _08120E50
	ldr r0, _08120E4C @ =0x0000FFFD
	ands r2, r0
	b _08120E54
	.align 2, 0
_08120E4C: .4byte 0x0000FFFD
_08120E50:
	movs r0, #2
	orrs r2, r0
_08120E54:
	strh r2, [r3]
	ldrh r1, [r3]
	movs r0, #1
	b _08120EAC
_08120E5C:
	adds r0, r4, #0
	adds r0, #0xb6
	ldrh r1, [r0]
	ldr r5, _08120E98 @ =0x0000FEFF
	ands r5, r1
	movs r6, #0
	strh r5, [r0]
	adds r1, r4, #0
	adds r1, #0xb4
	movs r3, #0
	ldrsh r2, [r1, r3]
	adds r3, r0, #0
	adds r4, r1, #0
	cmp r2, #0
	bge _08120EB2
	ldr r1, _08120E9C @ =0x0000FFFE
	ands r1, r5
	ldr r0, _08120EA0 @ =0x0000FFDF
	ands r1, r0
	adds r0, #0x10
	ands r1, r0
	strh r1, [r3]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08120EA8
	ldr r0, _08120EA4 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r3]
	b _08120EDA
	.align 2, 0
_08120E98: .4byte 0x0000FEFF
_08120E9C: .4byte 0x0000FFFE
_08120EA0: .4byte 0x0000FFDF
_08120EA4: .4byte 0x0000FFFB
_08120EA8:
	adds r0, r1, #0
	movs r1, #4
_08120EAC:
	orrs r0, r1
	strh r0, [r3]
	b _08120EDA
_08120EB2:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq _08120EC4
	ldr r0, _08120EC0 @ =0x0000FFDF
	ands r0, r5
	b _08120ECA
	.align 2, 0
_08120EC0: .4byte 0x0000FFDF
_08120EC4:
	movs r1, #0x20
	adds r0, r5, #0
	orrs r0, r1
_08120ECA:
	strh r0, [r3]
	ldrh r0, [r3]
	movs r1, #0x10
	orrs r1, r0
	strh r1, [r3]
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
_08120EDA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	.syntax divided
