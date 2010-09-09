//
//  VectorFieldEmitterFactory.m
//  Particles
//
//  Created by bschofil on 8/19/10.
//  Copyright 2010 ThoughtWorks. All rights reserved.
//

#import "VectorFieldEmitterFactory.h"
#import "VertexArray.h"
#import "VectorFieldPositionController.h"
#import "SinPositionColorController.h"
#import "ParticleEmitter.h"
#import "FollowParticleCameraController.h"
#import "Color.h"
#import "GLCamera.h"

@implementation VectorFieldEmitterFactory

- (id) create
{
	const int numberOfParticles = 65536;
	VertexArray* particles = [[VertexArray alloc] init: numberOfParticles];
	Color* colors = malloc(sizeof(Color) * numberOfParticles);

	NSMutableArray *controllers = [[NSMutableArray alloc] init];	
	[controllers addObject: [[VectorFieldPositionController alloc] initWithVertices:particles]];	
	[controllers addObject: [[SinPositionColorController alloc] init:particles withColors:colors]];
	[controllers addObject: [[FollowParticleCameraController alloc] initWithCamera: [GLCamera alloc] andPositionToFollow:[particles getVertices]]];
	
	return [[ParticleEmitter alloc] init: particles withColors:colors withControllers:controllers];
}

@end
