<?php
/**
 * Copyright 2021 Tennessee Tech University
 * This file is part of CSC 4610/4620 CAPSTONE project for Group 03
 * Authors: Scott Maday
 */

// Note: Namespace must match the project folder name
namespace DynamicMuseumWalk;

use Omeka\Module\AbstractModule;

use Laminas\Db\Adapter\AdapterInterface;
use Laminas\Db\ResultSet\ResultSet;
use Laminas\Db\TableGateway\TableGateway;
use Laminas\ModuleManager\ModuleManager;
use Laminas\ModuleManager\Feature\ConfigProviderInterface;
use Laminas\ServiceManager\ServiceLocatorInterface;
use Laminas\Mvc\MvcEvent;


class Module extends AbstractModule implements ConfigProviderInterface {

	public function onBootstrap(MvcEvent $event)
	{
		parent::onBootstrap($event);
		$this->addAclRules();
	}

	protected function addAclRules() {
		$acl = $this->getServiceLocator()->get("Omeka\Acl");
		/** NOTICE FOR USER STORY "As a business, I would like to have administrative rights to ensure no one is accessing my data without permission." **/
		// TODO restrict permissions for data-sensitive views (create an Admin view controller for that?)

		//if ($acl->userIsAllowed($resource, $privilege)) {
			//make current user allowed
		//}

		//if ($acl->isAllowed($user, $resource, $privilege)) {
			//make passed user allowed
		//}

		//$role = $user->getRole();
		//if ($acl->isAdminRole($role)) {
			//allow admin access
		//}

		// We may need to restructure and have two controllers such that there's Site\Controller\MuseumController and
		// SiteAdmin\Controller\[?]Controller where that controller is restricted to administrators and is responsible for rendering saves.phtml
		// You can delete these comments once the user story is complete
		$acl->allow(null, Controller\MuseumController::class);
	}

	public function getConfig() {
		return include (__DIR__ . "/config/module.config.php");
	}

	public function getServiceConfig()
	{
		return [
			'factories' => [
				Model\MuseumTable::class => function($container) {
					$tableGateway = $container->get(Model\MuseumTableGateway::class);
					return new Model\MuseumTable($tableGateway);
				},
				Model\MuseumTableGateway::class => function($container) {
					$dbAdapter = $container->get(AdapterInterface::class);
					$resultSetPrototype = new ResultSet();
					$resultSetPrototype->setArrayObjectPrototype(new Model\Museum());
					return new TableGateway('museum', $dbAdapter, null, $resultSetPrototype);
				},
			],
		];
	}
	public function getControllerConfig()
	{
		return [
			'factories' => [
				Controller\MuseumController::class => function($container) {
					return new Controller\MuseumController(
						$container->get(Model\MuseumTable::class),
					);
				}
			],
		];
	}
	//function name: install()
	//purpose: this function runs when the module is installed, it creates
	//a table in the database that will be used to store information
	public function install(ServiceLocatorInterface $serviceLocator)
	{
		$connection = $serviceLocator->get('Omeka\Connection');
		$sql =  'CREATE TABLE museum ( ';
		$sql .= ' id int AUTO_INCREMENT NOT NULL PRIMARY KEY,';
		$sql .= ' title varchar(100) NOT NULL )';
		$sql .= ' DEFAULT CHARACTER SET UTF8 ENGINE = InnoDB';

		$connection->exec($sql);
	}
	//function name: uninstall()
	//purpose: this function runs when the module is unistalled, it drops
	//the table that was created on install
	public function uninstall(ServiceLocatorInterface $serviceLocator)
	{
		$connection = $serviceLocator->get('Omeka\Connection');
		$sql = 'DROP TABLE IF EXISTS museum';
		$connection->exec($sql);
	}
}
