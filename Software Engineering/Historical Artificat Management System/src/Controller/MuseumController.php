<?php
/**
 * Copyright 2021 Tennessee Tech University
 * This file is part of CSC 4610/4620 CAPSTONE project for Group 03
 * Authors: Scott Maday
 */

namespace DynamicMuseumWalk\Controller;

use Laminas\Mime\Message as MimeMessage;
use Laminas\Mime\Part as MimePart;
use Laminas\Mvc\Controller\AbstractActionController;
use Omeka\Permissions\Acl;
use Laminas\View\Model\ViewModel;
use Laminas\Http\Headers;

/**
 * Controller for routes indicating one wishing to view a museum
 * @author Scott Maday
 */
class MuseumController extends AbstractActionController {
	private static $templateRoot = "museum";

	protected $acl;

	function __construct($acl) {
		$this->acl = $acl;
	}

	// Builds a view for the actions
	private function buildView(string $action) {
		$view = new ViewModel();
		$view->setTemplate(MuseumController::$templateRoot . "/$action");
		return $view;
	}
	public function buildParameterizedView(string $action)
	{
		// Get results from a possible query
		$query = $this->params()->fromQuery();
		$itemIds = $this->params()->fromQuery("items");
		$items = array();
		if($itemIds != null) {
			foreach($itemIds as $itemId) {
				array_push($items, $this->api()->read("items", $itemId)->getContent());	// TODO make more efficient
			}
		} else {
			$items = $query != null ? $this->api()->search("items", $query)->getContent() : array();
		}
		// Create view
		$view = $this->buildView($action);
		// Attatch variables
		$view->setVariable("query", $query);
		$view->setVariable("items", $items);
		return $view;
	}

	// AbstractActionController overloads

	// Re-routes to the generate action
	public function indexAction() {
		// NOTE urls denoting an action must be specific with museum/action since the new route table declares museum as a literal
		return $this->redirect()->toRoute("museum/action", ["action" => "generate"]);
	}

	// Responsible for the user selecting what they wish to generate the museum walk
	public function generateAction() {
		return $this->buildParameterizedView("generate");
	}

	// Responsible for viewing the museum walk on the web
	public function viewAction() {
		return $this->buildParameterizedView("view");
	}

	// Responsible for rendering individual slides of the museum walk
	public function slidesAction() {
		$num = $this->params("num");
		if($num == null) {
			print("No num parameter for slides");
			return $this->indexAction();
		}
		$response = $this->getResponse();
		$response->getHeaders()->addHeaderLine("Content-Type", "image/webp");
		$view = $this->buildParameterizedView("slides");
		$view->setVariable("item", $this->api()->read("items", $num)->getContent());
		$view->setTerminal(true);
		return $view;
	}

	// Responsible for saving the museum walk generated by the generate action
	public function savesAction() {
		return $this->buildParameterizedView("saves");

	}

	//TODO: Controls administrative rights
	


}


?>
