<?php
/**
 * Copyright 2021 Tennessee Tech University
 * This file is part of CSC 4610/4620 CAPSTONE project for Group 03
 * Authors: Scott Maday
 */

namespace DynamicMuseumWalk\Service;

use DynamicMuseumWalk\Controller\MuseumController;
use Laminas\ServiceManager\Factory\FactoryInterface;
use Interop\Container\ContainerInterface;

/**
 * Factory for creating the MuseumController, specifically to get and pass the ACL service to the controller
 * @author Scott Maday
 */
class MuseumControllerFactory implements FactoryInterface
{
	function __construct() {
	}

	public function __invoke(ContainerInterface $services, $requestedName, array $options = null)
	{
		return new MuseumController($services->get("Omeka\Acl"));
	}
}

?>