<?php
/**
 * Copyright 2021 Tennessee Tech University
 * This file is part of CSC 4610/4620 CAPSTONE project for Group 03
 * Authors: Scott Maday
 */

namespace DynamicMuseumWalk;

use Laminas\Router\Http\Segment;
use Laminas\Router\Http\Literal;
use Laminas\ServiceManager\Factory\InvokableFactory;

return [
	"controllers" => [
		"factories" => [
			Controller\MuseumController::class => Service\MuseumControllerFactory::class,
		],
	],
	"router" => [
		"routes" => [
			// TODO use site and siteadmin routes when separating permissions vs permissionless
			//"site" => [
				//"child_routes" => [
					"museum" => [
						"type" => Literal::class,
						"options" => [
							"route" => "/museum",
							"defaults" => [
								"controller" => Controller\MuseumController::class,
								"action" => "index",
							]
						],
						"may_terminate" => true,
						"child_routes" => [
							"slides" => [
								"type" => Segment::class,
								"options" => [
									"route" => "/slides/:num",
									"constraints" => [
										"num" => "[0-9]*",
									],
									"defaults" => [
										"action" => "slides",
									]
								]
							],
							"action" => [
								"type" => Segment::class,
								"options" => [
									"route" => "/:action",
									"constraints" => [
										"action" => "[a-zA-Z][a-zA-Z0-9_-]*",
									],
									"defaults" => [
										"action" => "generate",
									]
								]
							]
						]
					]
				//]
			//]
		],
	],
	
	"block_layouts" => [
		"invokables" => [
			"museum" => Admin\BlockLayout\MuseumBlockLayout::class
		]
	],
	"view_manager" => [
		"template_path_stack" => [
			dirname(__DIR__) . "/view",
		],
	]
];
